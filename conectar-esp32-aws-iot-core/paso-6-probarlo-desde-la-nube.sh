aws iot-data update-thing-shadow --thing-name mi-esp32 \
  --endpoint-url https://xxxxxxxxxxxxxx-ats.iot.us-east-1.amazonaws.com \
  --cli-binary-format raw-in-base64-out \
  --payload '{"state":{"desired":{"led":"on"}}}' \
  salida.json
