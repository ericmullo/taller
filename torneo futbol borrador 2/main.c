#include <stdio.h>
#include <stdlib.h>
#include "torneo.h"
#include "resultados.h"

int main() {
    ingresarEquipos();

    int opcion;
    printf("Seleccione una opción:\n");
    printf("1. Ingresar resultados manualmente\n");
    printf("2. Generar resultados automáticamente\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        ingresarResultadosManual();
    } else if (opcion == 2) {
        generarResultadosAutomatico();
    } else {
        printf("Opción inválida. Saliendo del programa.\n");
        return 0;
    }

    mostrarResultados();
    mostrarTablaPosiciones();

    return 0;
}


