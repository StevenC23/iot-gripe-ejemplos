export const handler = async (event) => {
  const serie = event.parameters?.NumeroSerie;
  const valido = await numeroDeSerieFabricado(serie);  // tu lista de números de serie fabricados
  return { allowProvisioning: Boolean(valido) };
};
