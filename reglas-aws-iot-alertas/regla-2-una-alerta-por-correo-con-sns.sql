SELECT concat('Temperatura alta en ', topic(2), ': ', cast(temperatura AS String), ' °C') AS mensaje
FROM 'casa-demo/+/telemetria'
WHERE temperatura > 30
