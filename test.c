#include "sala.h"
#include <stdio.h>

int main(){

  printf("Probando la biblioteca para la gestión de la sala de cine:\n\n");

  // Intentando elimiar una sala que no existe
  printf("Intentando eliminar una sala inexistente: ");
  printf("%s\n\n", elimina_sala()==0 ? "Se ha eliminado la sala." : "Error al eliminar.");

  // Creando la sala con 10 asientos
  printf("Intentando crear una sala con 10 asientos: ");
  printf("%s\n", crea_sala(10) == 10 ? "Se ha creado la sala correctamente." : "Error al crear la sala.");
  printf("Intentando crear otra sala (Debería dar error): ");
  printf("%s\n\n", crea_sala(5) == 5 ? "Otra sala creada correctamente." : "Error al crear otra sala.");

  // Reservando y liberando asientos
  printf("Reservando un asiento:\n");
  printf("Originalmente hay %d asientos libres y %d asientos ocupados.\n", asientos_libres(), asientos_ocupados());
  int asiento = reserva_asiento(20);
  printf("Reservamos un asiento, ahora hay %d asientos libres y %d asientos ocupados.\n", asientos_libres(), asientos_ocupados());
  printf("El ID del usuario que reservó el asiento es %d\n", estado_asiento(asiento));
  printf("Liberamos el asiento: %s\n", libera_asiento(asiento) == -1 ? "Error." : "Liberado correctamente.");
  printf("Al final hay %d asientos libres y %d asientos ocupados.\n\n", asientos_libres(), asientos_ocupados());
  
  // Intentando liberar un asiento que ya está libre
  printf("Liberando asiento previamente libre: ");
  printf("%s\n\n", libera_asiento(4) == -1 ? "Error." : "Asiento liberado correctamente.");

  // Intentando reservar toda la sala
  printf("Intentando reservar más asientos de los disponibles:\n");
  while (asientos_libres()) reserva_asiento(10);
  printf("Se han reservado todos los asientos, quedan %d asientos libres y hay %d asientos ocupados.\n", asientos_libres(), asientos_ocupados());
  printf("Reservando otro asiento: %s\n\n", reserva_asiento(10) == -1 ? "Error." : "Asiento reservado correctamente.");
  
  // Probando el getter de capacidad
  printf("La sala tiene %d asientos.\n\n", capacidad_sala());

  // Eliminando la sala
  printf("Eliminando la sala: %s\n", elimina_sala() == -1 ? "Error." : "Sala eliminada correctamente.");
  
  return 0;
}
