aws sns create-topic --name alertas-casa
aws sns subscribe --topic-arn arn:aws:sns:REGION:CUENTA:alertas-casa \
  --protocol email --notification-endpoint tu@correo.com
# Confirma la suscripción desde el enlace que llega al correo
