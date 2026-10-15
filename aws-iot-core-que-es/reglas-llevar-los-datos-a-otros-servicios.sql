SELECT temperatura, humedad, timestamp() AS ts
FROM 'casa/+/sensores'
WHERE temperatura > 30
