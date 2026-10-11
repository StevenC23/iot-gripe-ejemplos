arduino-cli compile --fqbn esp32:esp32:esp32s3 --export-binaries --output-dir build/hub firmware/hub
arduino-cli compile --fqbn esp32:esp32:esp32c3 --export-binaries --output-dir build/nodo firmware/nodo
# Copia los *.ino.merged.bin a public/firmware/ como hub.bin y nodo.bin
