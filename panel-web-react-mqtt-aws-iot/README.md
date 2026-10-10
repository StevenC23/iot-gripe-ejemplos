# Panel web con React y MQTT sobre AWS IoT Core

Código del artículo **[Panel web con React y MQTT sobre AWS IoT Core](https://iot.gripe/blog/panel-web-react-mqtt-aws-iot)**, publicado en [iot.gripe](https://iot.gripe).

Cómo conectar una app React a AWS IoT Core por MQTT sobre WebSocket: credenciales de Cognito, URL firmada con SigV4, la política de IoT que suele faltar, el Device Shadow en la interfaz y la reconexión.

| Archivo | Sección del artículo |
| --- | --- |
| [`paso-1-credenciales-temporales-con-cognito.ts`](paso-1-credenciales-temporales-con-cognito.ts) | Paso 1: credenciales temporales con Cognito |
| [`la-politica-de-iot-que-suele-faltar.sh`](la-politica-de-iot-que-suele-faltar.sh) | La política de IoT que suele faltar |
| [`paso-2-firmar-la-url.ts`](paso-2-firmar-la-url.ts) | Paso 2: firmar la URL |
| [`paso-3-conectar-y-pedir-el-estado.ts`](paso-3-conectar-y-pedir-el-estado.ts) | Paso 3: conectar y pedir el estado |
| [`paso-4-mostrar-solo-lo-confirmado.ts`](paso-4-mostrar-solo-lo-confirmado.ts) | Paso 4: mostrar solo lo confirmado |
| [`paso-5-desconectarse-cuando-nadie-mira.ts`](paso-5-desconectarse-cuando-nadie-mira.ts) | Paso 5: desconectarse cuando nadie mira |

Algunos archivos son fragmentos que se entienden junto con el artículo: ahí está la explicación paso a paso.
