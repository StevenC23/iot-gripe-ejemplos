import { SignatureV4 } from "@smithy/signature-v4";
import { HttpRequest } from "@smithy/protocol-http";
import { formatUrl } from "@aws-sdk/util-format-url";
import { Sha256 } from "@aws-crypto/sha256-js";

async function urlFirmada() {
  const { accessKeyId, secretAccessKey, sessionToken } = await credenciales();

  const signer = new SignatureV4({
    service: "iotdevicegateway",
    region: REGION,
    credentials: { accessKeyId, secretAccessKey },  // sin sessionToken
    sha256: Sha256,
  });

  const firmada = await signer.presign(
    new HttpRequest({ method: "GET", protocol: "wss:", hostname: IOT_ENDPOINT, path: "/mqtt", headers: { host: IOT_ENDPOINT } }),
    { expiresIn: 3600 }
  );
  return `${formatUrl(firmada)}&X-Amz-Security-Token=${encodeURIComponent(sessionToken!)}`;
}
