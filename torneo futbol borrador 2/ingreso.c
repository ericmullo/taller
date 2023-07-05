#include <stdio.h>
#include <string.h>
#include "ingreso.h"

void ingresarEquipos() {
    FILE *archivo = fopen("equipos.txt", "w");//se crea el archivo txt donde se guardan los equipos.
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo equipos.txt\n");
        return;
    }

    char equipo[100];
    while (1) {
        printf("Ingrese el nombre del equipo (o 'terminar' para finalizar): ");
        scanf("%s", equipo);

        if (strcmp(equipo, "terminar") == 0) {//strcmp:compara y devuelve 0 si son iguales las cadenas
            break;
        }

        fprintf(archivo, "%s\n", equipo);
    }

    fclose(archivo);
}
