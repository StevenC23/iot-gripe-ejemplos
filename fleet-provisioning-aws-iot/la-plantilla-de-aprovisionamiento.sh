aws iot create-provisioning-template \
  --template-name casa-demo \
  --provisioning-role-arn arn:aws:iam::CUENTA:role/aprovisionamiento-iot \
  --template-body file://plantilla.json \
  --enabled
