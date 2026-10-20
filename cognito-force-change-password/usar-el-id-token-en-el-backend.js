import { CognitoJwtVerifier } from "aws-jwt-verify";

const verificador = CognitoJwtVerifier.create({ userPoolId: USER_POOL_ID, tokenUse: "id", clientId: APP_CLIENT_ID });
const datos = await verificador.verify(idToken);  // lanza un error si es inválido o venció
const casaId = datos["custom:casaId"];
