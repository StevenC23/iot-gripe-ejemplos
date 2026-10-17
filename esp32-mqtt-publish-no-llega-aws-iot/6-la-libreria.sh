mosquitto_pub --cafile AmazonRootCA1.pem --cert certificado.pem.crt --key privada.pem.key \
  -h TU-ENDPOINT-ats.iot.us-east-1.amazonaws.com -p 8883 \
  -i prueba-pc -t casa/prueba -m '{"hola":1}'
