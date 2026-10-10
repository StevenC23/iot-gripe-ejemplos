import {
  CognitoIdentityProviderClient,
  InitiateAuthCommand,
} from "@aws-sdk/client-cognito-identity-provider";

const client = new CognitoIdentityProviderClient({ region: REGION });

export async function iniciarSesion(usuario: string, password: string) {
  const r = await client.send(
    new InitiateAuthCommand({
      AuthFlow: "USER_PASSWORD_AUTH",
      ClientId: APP_CLIENT_ID,
      AuthParameters: { USERNAME: usuario, PASSWORD: password },
    })
  );

  if (r.ChallengeName === "NEW_PASSWORD_REQUIRED") {
    // Primer login con contraseña temporal: ver más abajo
    throw new NuevaPasswordRequerida(usuario, r.Session!);
  }
  return r.AuthenticationResult;  // IdToken, AccessToken, RefreshToken
}
