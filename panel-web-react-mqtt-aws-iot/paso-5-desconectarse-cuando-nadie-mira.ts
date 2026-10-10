let temporizador: ReturnType<typeof setTimeout> | null = null;

document.addEventListener("visibilitychange", () => {
  if (document.hidden) {
    temporizador = setTimeout(() => cliente.end(), 10_000);
  } else {
    if (temporizador) clearTimeout(temporizador);
    if (!cliente.connected) reconectar();  // URL nueva, suscribirse y pedir el estado
  }
});
