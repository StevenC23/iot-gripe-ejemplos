import * as cdk from "aws-cdk-lib";
import * as dynamodb from "aws-cdk-lib/aws-dynamodb";
import * as lambda from "aws-cdk-lib/aws-lambda";
import * as iam from "aws-cdk-lib/aws-iam";
import * as iot from "aws-cdk-lib/aws-iot";
import { NodejsFunction } from "aws-cdk-lib/aws-lambda-nodejs";
import { Construct } from "constructs";

export class CasaDemoStack extends cdk.Stack {
  constructor(scope: Construct, id: string, props?: cdk.StackProps) {
    super(scope, id, props);

    const thingName = "mi-esp32";

    // 1. Tabla de dispositivos (con estado: no se borra con el stack)
    const tabla = new dynamodb.Table(this, "Dispositivos", {
      partitionKey: { name: "casaId", type: dynamodb.AttributeType.STRING },
      sortKey: { name: "dispositivoId", type: dynamodb.AttributeType.STRING },
      billingMode: dynamodb.BillingMode.PAY_PER_REQUEST,
      removalPolicy: cdk.RemovalPolicy.RETAIN,
      pointInTimeRecoverySpecification: { pointInTimeRecoveryEnabled: true },
    });

    // 2. Lambda de la API (parte 8)
    const api = new NodejsFunction(this, "ApiOrdenes", {
      entry: "lambda/api-ordenes.ts",
      runtime: lambda.Runtime.NODEJS_22_X,
      timeout: cdk.Duration.seconds(10),
      memorySize: 256,
      environment: { THING_NAME: thingName, TABLA: tabla.tableName },
    });
    tabla.grantReadData(api);
    api.addToRolePolicy(
      new iam.PolicyStatement({
        actions: ["iot:UpdateThingShadow"],
        resources: [`arn:aws:iot:${this.region}:${this.account}:thing/${thingName}`],
      })
    );
    const url = api.addFunctionUrl({ authType: lambda.FunctionUrlAuthType.NONE });

    // 3. Política de IoT del dispositivo (parte 13)
    new iot.CfnPolicy(this, "PoliticaDispositivo", {
      policyName: "casa-demo-dispositivo",
      policyDocument: {
        Version: "2012-10-17",
        Statement: [
          {
            Effect: "Allow",
            Action: "iot:Connect",
            Resource: `arn:aws:iot:${this.region}:${this.account}:client/\${iot:Connection.Thing.ThingName}`,
          },
          // ... Subscribe, Receive y Publish sobre los tópicos de su Shadow
        ],
      },
    });

    new cdk.CfnOutput(this, "ApiUrl", { value: url.url });
  }
}
