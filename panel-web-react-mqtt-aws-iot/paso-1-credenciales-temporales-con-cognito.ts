import { fromCognitoIdentityPool } from "@aws-sdk/credential-providers";

const credenciales = fromCognitoIdentityPool({
  clientConfig: { region: REGION },
  identityPoolId: IDENTITY_POOL_ID,
  logins: { [`cognito-idp.${REGION}.amazonaws.com/${USER_POOL_ID}`]: idToken },
});
