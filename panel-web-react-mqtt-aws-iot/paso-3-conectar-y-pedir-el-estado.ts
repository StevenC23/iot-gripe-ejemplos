import mqtt from "mqtt";

const base = `$aws/things/${THING}/shadow`;
const cliente = mqtt.connect(await urlFirmada(), {
  clientId: `panel-${crypto.randomUUID()}`,
  protocolVersion: 4,     // MQTT 3.1.1
  reconnectPeriod: 5000,
  connectTimeout: 10000,
});

cliente.on("connect", () => {
  // Primero suscribirse; pedir el estado solo cuando AWS confirmó la suscripción
  cliente.subscribe([`${base}/get/accepted`, `${base}/update/accepted`], () => {
    cliente.publish(`${base}/get`, "");
  });
});
