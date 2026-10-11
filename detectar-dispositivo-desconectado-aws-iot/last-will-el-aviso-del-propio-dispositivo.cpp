client.setWill("casa-demo/mi-esp32/estado", "{\"conectado\":false}", true, 1);
client.connect(THING_NAME);
client.publish("casa-demo/mi-esp32/estado", "{\"conectado\":true}", true, 1);
