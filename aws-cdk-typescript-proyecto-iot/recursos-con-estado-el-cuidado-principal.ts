const tabla = dynamodb.Table.fromTableName(this, "TablaExistente", "dispositivos");
tabla.grantReadData(api);  // funciona igual, pero CDK nunca la crea ni la borra
