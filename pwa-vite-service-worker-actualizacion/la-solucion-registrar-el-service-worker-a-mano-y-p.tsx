import { useRegisterSW } from "virtual:pwa-register/react";

const BUSCAR_ACTUALIZACION_MS = 30 * 60 * 1000;  // cada 30 minutos

export default function App() {
  useRegisterSW({
    onRegisteredSW(_swUrl, registration) {
      if (!registration) return;
      setInterval(() => registration.update(), BUSCAR_ACTUALIZACION_MS);
    },
  });

  // ...
}
