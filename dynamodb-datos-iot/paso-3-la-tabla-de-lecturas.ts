// Lecturas del sensor en las últimas 24 horas
const desde = new Date(Date.now() - 24 * 3600 * 1000).toISOString();

const { Items } = await db.send(
  new QueryCommand({
    TableName: "lecturas",
    KeyConditionExpression: "dispositivoId = :d AND ts >= :desde",
    ExpressionAttributeValues: { ":d": "sensor-patio", ":desde": desde },
  })
);
