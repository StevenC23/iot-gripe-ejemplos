#define MAX_HORARIOS 10

struct Horario {
  uint8_t hora;
  uint8_t minuto;
  uint8_t salida;  // qué relé
  uint8_t valor;   // 0 = apagar, 1 = encender
};

Horario horarios[MAX_HORARIOS];
size_t totalHorarios = 0;

void guardarHorarios() {
  prefs.begin("config", false);
  prefs.putUChar("n_hor", (uint8_t)totalHorarios);
  prefs.putBytes("horarios", horarios, totalHorarios * sizeof(Horario));
  prefs.end();
}

void cargarHorarios() {
  prefs.begin("config", true);
  size_t n = prefs.getUChar("n_hor", 0);
  if (n > MAX_HORARIOS) n = MAX_HORARIOS;  // nunca confíes en lo que hay en memoria
  if (n > 0) prefs.getBytes("horarios", horarios, n * sizeof(Horario));
  totalHorarios = n;
  prefs.end();
}
