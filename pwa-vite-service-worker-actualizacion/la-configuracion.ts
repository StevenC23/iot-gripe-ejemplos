import react from "@vitejs/plugin-react";
import { defineConfig } from "vite";
import { VitePWA } from "vite-plugin-pwa";

export default defineConfig({
  plugins: [
    react(),
    VitePWA({
      registerType: "autoUpdate",
      injectRegister: false,  // el registro se hace a mano, ver más abajo
      includeAssets: ["favicon-32x32.png", "apple-touch-icon.png"],
      workbox: {
        globIgnores: ["**/descargas/**"],  // no precachear archivos grandes que casi nadie usa
      },
      manifest: {
        name: "Casa Demo",
        short_name: "Casa",
        description: "Panel de control de la casa",
        lang: "es",
        theme_color: "#0f766e",
        background_color: "#ffffff",
        display: "standalone",  // se abre sin la barra del navegador
        start_url: "/",
        scope: "/",
        icons: [
          { src: "pwa-192x192.png", sizes: "192x192", type: "image/png" },
          { src: "pwa-512x512.png", sizes: "512x512", type: "image/png" },
          { src: "pwa-512x512.png", sizes: "512x512", type: "image/png", purpose: "maskable" },
        ],
      },
    }),
  ],
});
