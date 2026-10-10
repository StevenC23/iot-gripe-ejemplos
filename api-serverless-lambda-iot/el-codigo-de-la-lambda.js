import { IoTDataPlaneClient, UpdateThingShadowCommand } from "@aws-sdk/client-iot-data-plane";
import { SSMClient, GetParameterCommand } from "@aws-sdk/client-ssm";
import { timingSafeEqual } from "node:crypto";

const iot = new IoTDataPlaneClient({});
const ssm = new SSMClient({});

const THING = process.env.THING_NAME;                  // el dispositivo que controla esta API
const SALIDAS = new Set(["sala", "cocina"]);           // lista blanca de claves del Shadow
let tokenEsperado;                                     // caché por contenedor

async function obtenerToken() {
  if (!tokenEsperado) {
    const r = await ssm.send(new GetParameterCommand({ Name: process.env.TOKEN_PARAM, WithDecryption: true }));
    tokenEsperado = Buffer.from(r.Parameter.Value);
  }
  return tokenEsperado;
}

const respuesta = (statusCode, cuerpo) => ({
  statusCode,
  headers: { "Content-Type": "application/json" },
  body: JSON.stringify(cuerpo),
});

export const handler = async (event) => {
  // 1. Quién llama
  const recibido = Buffer.from(event.headers?.["x-api-token"] ?? "");
  const esperado = await obtenerToken();
  if (recibido.length !== esperado.length || !timingSafeEqual(recibido, esperado)) {
    return respuesta(401, { error: "No autorizado" });
  }

  // 2. Qué pide
  let orden;
  try {
    orden = JSON.parse(event.body ?? "{}");
  } catch {
    return respuesta(400, { error: "JSON inválido" });
  }
  const { salida, valor } = orden;
  if (!SALIDAS.has(salida) || !["on", "off"].includes(valor)) {
    return respuesta(400, { error: "Orden no válida" });
  }

  // 3. Cambiar el estado deseado
  const payload = JSON.stringify({ state: { desired: { [salida]: valor } } });
  await iot.send(new UpdateThingShadowCommand({ thingName: THING, payload: Buffer.from(payload) }));

  return respuesta(200, { ok: true, salida, valor });
};
