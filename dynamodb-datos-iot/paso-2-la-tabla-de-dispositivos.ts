import { DynamoDBClient } from "@aws-sdk/client-dynamodb";
import { DynamoDBDocumentClient, QueryCommand } from "@aws-sdk/lib-dynamodb";

const db = DynamoDBDocumentClient.from(new DynamoDBClient({}));

const { Items } = await db.send(
  new QueryCommand({
    TableName: "dispositivos",
    KeyConditionExpression: "casaId = :c",
    ExpressionAttributeValues: { ":c": "casa-demo" },
  })
);
