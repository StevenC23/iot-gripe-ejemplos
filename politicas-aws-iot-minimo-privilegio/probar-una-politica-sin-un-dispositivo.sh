aws iot test-authorization \
  --principal <certificateArn> \
  --client-id mi-esp32 \
  --auth-infos '[{"actionType":"PUBLISH","resources":["arn:aws:iot:REGION:CUENTA:topic/$aws/things/otro-esp32/shadow/update"]}]'
