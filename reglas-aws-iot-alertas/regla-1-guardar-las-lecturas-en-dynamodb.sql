SELECT temperatura, humedad,
       topic(2) AS dispositivoId,
       parse_time("yyyy-MM-dd'T'HH:mm:ss'Z'", timestamp()) AS ts,
       floor(timestamp() / 1000) + 2592000 AS expira
FROM 'casa-demo/+/telemetria'
