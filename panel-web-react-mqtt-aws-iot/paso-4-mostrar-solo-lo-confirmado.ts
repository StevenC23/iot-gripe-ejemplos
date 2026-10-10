cliente.on("message", (_topic, buffer) => {
  let doc: { state?: { reported?: Record<string, string> } };
  try {
    doc = JSON.parse(buffer.toString());
  } catch {
    return;
  }
  const reportado = doc.state?.reported;  // nunca desired
  if (reportado) setEstado((prev) => ({ ...prev, ...reportado }));
});

function alternar(salida: string, encender: boolean) {
  setPendiente((prev) => ({ ...prev, [salida]: true }));
  cliente.publish(`${base}/update`, JSON.stringify({ state: { desired: { [salida]: encender ? "on" : "off" } } }));
}
