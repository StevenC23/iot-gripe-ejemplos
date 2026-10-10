npx tsc --noEmit   # el código compila
npx cdk synth      # genera la plantilla de CloudFormation
npx cdk diff       # qué va a cambiar en la cuenta
npx cdk deploy     # despliega (pide confirmación si cambian permisos IAM)
