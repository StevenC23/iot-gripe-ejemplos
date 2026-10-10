import { AdminCreateUserCommand } from "@aws-sdk/client-cognito-identity-provider";

await cognito.send(
  new AdminCreateUserCommand({
    UserPoolId: USER_POOL_ID,
    Username: email,
    TemporaryPassword: passwordTemporal,  // si lo omites, Cognito genera una
    UserAttributes: [
      { Name: "email", Value: email },
      { Name: "email_verified", Value: "true" },
      { Name: "custom:casaId", Value: "casa-demo" },
    ],
  })
);
