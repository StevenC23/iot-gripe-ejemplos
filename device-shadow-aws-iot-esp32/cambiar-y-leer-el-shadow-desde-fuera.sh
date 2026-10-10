aws iot-data update-thing-shadow --thing-name mi-esp32 \
  --cli-binary-format raw-in-base64-out \
  --payload '{"state":{"desired":{"sala":"on"}}}' salida.json
