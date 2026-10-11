import "esp-web-tools";  // registra el custom element

export function FlashFirmwareTab() {
  return (
    <section>
      <h2>Flashear firmware</h2>
      <p className="warning">
        Esto borra toda la configuración de la placa. Después tendrás que configurarla de nuevo desde su red Wi-Fi.
      </p>
      <esp-web-install-button manifest="/firmware/manifest.json">
        <button slot="activate">Conectar y flashear placa</button>
        <span slot="unsupported">Tu navegador no puede flashear placas. Usa Chrome o Edge en un computador.</span>
        <span slot="not-allowed">Abre el panel por HTTPS para poder flashear.</span>
      </esp-web-install-button>
    </section>
  );
}
