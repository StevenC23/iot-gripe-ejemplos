# Aprovisionar dispositivos en AWS IoT con Fleet Provisioning

Código del artículo **[Aprovisionar dispositivos en AWS IoT con Fleet Provisioning](https://iot.gripe/blog/fleet-provisioning-aws-iot)**, publicado en [iot.gripe](https://iot.gripe).

Cómo dar a cada ESP32 su propio certificado sin quemarlo en el firmware: Fleet Provisioning por claim y por usuario de confianza, plantillas de aprovisionamiento, el hook de validación y alternativas.

| Archivo | Sección del artículo |
| --- | --- |
| [`la-plantilla-de-aprovisionamiento.json`](la-plantilla-de-aprovisionamiento.json) | La plantilla de aprovisionamiento |
| [`la-plantilla-de-aprovisionamiento.sh`](la-plantilla-de-aprovisionamiento.sh) | La plantilla de aprovisionamiento |
| [`la-politica-del-certificado-de-claim.json`](la-politica-del-certificado-de-claim.json) | La política del certificado de claim |
| [`lo-que-hace-el-dispositivo.cpp`](lo-que-hace-el-dispositivo.cpp) | Lo que hace el dispositivo |
| [`validar-quien-se-registra-el-pre-provisioning-hook.js`](validar-quien-se-registra-el-pre-provisioning-hook.js) | Validar quién se registra: el pre-provisioning hook |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
