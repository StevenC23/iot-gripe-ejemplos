void aplicarHorarios(const Horario* nuevos, size_t n) {
  bool cambio = n != totalHorarios || memcmp(nuevos, horarios, n * sizeof(Horario)) != 0;
  if (!cambio) return;  // nada cambió: no se toca la flash

  memcpy(horarios, nuevos, n * sizeof(Horario));
  totalHorarios = n;
  guardarHorarios();
}
