# Ejemplos de iot.gripe

Código de los artículos de **[iot.gripe](https://iot.gripe)**: ESP32, ESP-NOW, AWS IoT Core, serverless, Java y Spring Boot en la nube, en español.

Cada carpeta corresponde a un artículo y tiene un README con el enlace a la explicación completa. El repositorio se actualiza a medida que se publican artículos nuevos.

| Fecha | Artículo | Archivos |
| --- | --- | --- |
| 2026-09-30 | [Arquitectura de una casa inteligente con ESP32 y AWS: las piezas y cómo encajan](arquitectura-casa-inteligente-esp32-aws/) | 1 |
| 2026-10-01 | [ESP32-S3 vs ESP32-C3: cuál elegir según el papel del dispositivo](esp32-s3-vs-esp32-c3/) | 3 |
| 2026-10-02 | [Conectar un ESP32 a AWS IoT Core paso a paso](conectar-esp32-aws-iot-core/) | 9 |
| 2026-10-03 | [ESP-NOW paso a paso: enviar órdenes entre ESP32 con confirmación](esp-now-esp32-paso-a-paso/) | 3 |
| 2026-10-04 | [Device Shadow en AWS IoT: estado deseado y reportado con un ESP32](device-shadow-aws-iot-esp32/) | 4 |
| 2026-10-04 | [NVS y Preferences en ESP32: guardar configuración que sobrevive cortes](nvs-preferences-esp32/) | 5 |
| 2026-10-05 | [DynamoDB para IoT: cómo modelar dispositivos y lecturas de sensores](dynamodb-datos-iot/) | 3 |
| 2026-10-05 | [API serverless para controlar un ESP32 con AWS Lambda](api-serverless-lambda-iot/) | 3 |
| 2026-10-06 | [Controlar un ESP32 con Siri usando Atajos, paso a paso](controlar-esp32-con-siri-atajos/) | 1 |
| 2026-10-06 | [Panel web con React y MQTT sobre AWS IoT Core](panel-web-react-mqtt-aws-iot/) | 6 |
| 2026-10-07 | [Login con Amazon Cognito: usuarios, tokens y el estado FORCE_CHANGE_PASSWORD](cognito-force-change-password/) | 5 |
| 2026-10-07 | [AWS CDK con TypeScript para un proyecto IoT: infraestructura como código](aws-cdk-typescript-proyecto-iot/) | 4 |
| 2026-10-08 | [Políticas de AWS IoT: mínimo privilegio para cada dispositivo](politicas-aws-iot-minimo-privilegio/) | 3 |
| 2026-10-08 | [Reglas de AWS IoT: guardar datos y enviar alertas sin servidores](reglas-aws-iot-alertas/) | 8 |
| 2026-10-09 | [Convertir un panel web en PWA con Vite (y que se actualice)](pwa-vite-service-worker-actualizacion/) | 4 |
| 2026-10-09 | [Portal cautivo en ESP32: configurar el Wi-Fi sin reprogramar](portal-cautivo-esp32-wifi/) | 5 |
| 2026-10-10 | [Aprovisionar dispositivos en AWS IoT con Fleet Provisioning](fleet-provisioning-aws-iot/) | 5 |
| 2026-10-10 | [Bombillo inteligente DIY con ESP32-C3 e interruptor de pared que funciona sin internet](bombillo-inteligente-esp32-c3-interruptor/) | 3 |
| 2026-10-11 | [Flashear un ESP32 desde el navegador con ESP Web Tools, sin instalar nada](flashear-esp32-desde-navegador/) | 6 |
| 2026-10-11 | [Saber si un ESP32 está conectado: eventos de ciclo de vida en AWS IoT](detectar-dispositivo-desconectado-aws-iot/) | 5 |

## Cómo usarlo

- **Sketches de Arduino** (`.ino`): ábrelos con el Arduino IDE. Cada sketch está en una carpeta con su mismo nombre, como pide el IDE.
- **Credenciales**: los ejemplos usan valores ficticios. Donde haya un `secrets.h.example`, cópialo como `secrets.h` y completa tus datos. Nunca subas certificados ni contraseñas a un repositorio.
- **Fragmentos**: algunos archivos son partes de un programa más grande. El artículo de cada carpeta explica dónde va cada uno.

## Licencia

[MIT](LICENSE): úsalo, modifícalo y compártelo. Si te sirve, un enlace a [iot.gripe](https://iot.gripe) se agradece.
