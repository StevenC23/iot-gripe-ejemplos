aws iot create-policy --policy-name mi-esp32-policy \
  --policy-document file://policy.json

aws iot attach-policy --policy-name mi-esp32-policy \
  --target <certificateArn>

aws iot attach-thing-principal --thing-name mi-esp32 \
  --principal <certificateArn>
