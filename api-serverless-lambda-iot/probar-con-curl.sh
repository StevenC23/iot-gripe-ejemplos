# Sin token: 401
curl -i -X POST "$URL" -d '{"salida":"sala","valor":"on"}'

# Orden válida: 200
curl -i -X POST "$URL" -H "x-api-token: $TOKEN" \
  -H "Content-Type: application/json" -d '{"salida":"sala","valor":"on"}'

# Salida desconocida: 400
curl -i -X POST "$URL" -H "x-api-token: $TOKEN" -d '{"salida":"garaje","valor":"on"}'
