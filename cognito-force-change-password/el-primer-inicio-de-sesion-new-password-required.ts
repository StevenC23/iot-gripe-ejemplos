import { RespondToAuthChallengeCommand } from "@aws-sdk/client-cognito-identity-provider";

export async function completarNuevaPassword(usuario: string, sesion: string, nueva: string) {
  const r = await client.send(
    new RespondToAuthChallengeCommand({
      ClientId: APP_CLIENT_ID,
      ChallengeName: "NEW_PASSWORD_REQUIRED",
      Session: sesion,
      ChallengeResponses: { USERNAME: usuario, NEW_PASSWORD: nueva },
    })
  );
  return r.AuthenticationResult;
}
