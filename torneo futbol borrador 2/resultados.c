#include <stdio.h>
#include <string.h>
#include "resultados.h"

void mostrarResultados() {
    FILE *resultadosArchivo = fopen("resultados.txt", "r");
    if (resultadosArchivo == NULL) {
        printf("No se pudo abrir el archivo resultados.txt\n");
        return;
    }

    printf("Resultados de los partidos:\n");
    printf("Equipo 1\tEquipo 2       Goles: Equipo 1\t      Equipo 2\n");
    printf("------------------------------------------------------------------\n");

    char equipo1[100], equipo2[100];
    int goles1, goles2;

    while (fscanf(resultadosArchivo, "%[^,],%[^,],%d,%d\n", equipo1, equipo2, &goles1, &goles2) == 4) {
        printf("%s\t\t%s\t\t\t%d\t\t%d\n", equipo1, equipo2, goles1, goles2);
    }

    fclose(resultadosArchivo);
}

void mostrarTablaPosiciones() {
    FILE *equiposArchivo = fopen("equipos.txt", "r");
    if (equiposArchivo == NULL) {
        printf("No se pudo abrir el archivo equipos.txt\n");
        return;
    }

    FILE *resultadosArchivo = fopen("resultados.txt", "r");
    if (resultadosArchivo == NULL) {
        printf("No se pudo abrir el archivo resultados.txt\n");
        fclose(equiposArchivo);
        return;
    }

    char equipo[100];
    int numEquipos = 0;

    // Contador del numero de equipos leyendo el equipos.txt
    while (fscanf(equiposArchivo, "%s", equipo) == 1) {
        numEquipos++;
    }

    fclose(equiposArchivo);

    // Volver a abrir el archivo equipos.txt para leer los nombres de los equipos y almacenarlos
    equiposArchivo = fopen("equipos.txt", "r");
    if (equiposArchivo == NULL) {
        printf("No se pudo abrir el archivo equipos.txt\n");
        return;
    }

    char equiposOrdenados[numEquipos][100]; // Matriz para almacenar los nombres de los equipos

    int contEquipos = 0;
    while (fscanf(equiposArchivo, "%s", equipo) == 1) {
        strcpy(equiposOrdenados[contEquipos], equipo);
        contEquipos++;
    }

    fclose(equiposArchivo);

    // Inicializar puntos de cada equipo
    int puntos[numEquipos];
    for (int i = 0; i < numEquipos; i++) {
        puntos[i] = 0;
    }

    // Calcular puntos por equipo
    char equipo1[100], equipo2[100];
    int goles1, goles2;

    while (fscanf(resultadosArchivo, "%[^,],%[^,],%d,%d\n", equipo1, equipo2, &goles1, &goles2) == 4) {
        for (int i = 0; i < numEquipos; i++) {
            if (strcmp(equipo1, equiposOrdenados[i]) == 0) {
                if (goles1 > goles2) {
                    puntos[i] += 3;
                } else if (goles1 == goles2) {
                    puntos[i] += 1;
                }
            }
            if (strcmp(equipo2, equiposOrdenados[i]) == 0) {
                if (goles2 > goles1) {
                    puntos[i] += 3;
                } else if (goles2 == goles1) {
                    puntos[i] += 1;
                }
            }
        }
    }

    fclose(resultadosArchivo);

    // Ordenar equipos según puntos usando el método de la burbuja
    for (int i = 0; i < numEquipos - 1; i++) {
        for (int j = 0; j < numEquipos - i - 1; j++) {
            if (puntos[j] < puntos[j + 1]) {
                int temp = puntos[j];
                puntos[j] = puntos[j + 1];
                puntos[j + 1] = temp;

                char tempEquipo[100];
                strcpy(tempEquipo, equiposOrdenados[j]);
                strcpy(equiposOrdenados[j], equiposOrdenados[j + 1]);
                strcpy(equiposOrdenados[j + 1], tempEquipo);
            }
        }
    }

    // Mostrar tabla de posiciones
    printf("Tabla de posiciones:\n");
    printf("Equipo\t\tPuntos\n");
    printf("--------------------\n");

    for (int i = 0; i < numEquipos; i++) {
        printf("%s\t\t%d\n", equiposOrdenados[i], puntos[i]);
    }
}



