aws iot create-thing --thing-name mi-esp32

aws iot create-keys-and-certificate --set-as-active \
  --certificate-pem-outfile certificate.pem.crt \
  --public-key-outfile public.pem.key \
  --private-key-outfile private.pem.key
# Guarda el "certificateArn" que devuelve este comando

curl -o AmazonRootCA1.pem https://www.amazontrust.com/repository/AmazonRootCA1.pem
