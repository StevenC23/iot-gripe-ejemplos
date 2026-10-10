import { ForgotPasswordCommand, ConfirmForgotPasswordCommand } from "@aws-sdk/client-cognito-identity-provider";

await client.send(new ForgotPasswordCommand({ ClientId: APP_CLIENT_ID, Username: usuario }));
// El usuario recibe un código por correo y lo escribe en la app
await client.send(
  new ConfirmForgotPasswordCommand({ ClientId: APP_CLIENT_ID, Username: usuario, ConfirmationCode: codigo, Password: nueva })
);
