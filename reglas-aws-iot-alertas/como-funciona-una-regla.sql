SELECT temperatura, humedad, topic(2) AS dispositivoId, timestamp() AS ts
FROM 'casa-demo/+/telemetria'
WHERE temperatura > 30
