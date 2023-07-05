#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingreso.h"
#include "torneo.h"

void ingresarResultadosManual() {
    FILE *equiposArchivo = fopen("equipos.txt", "r");
    if (equiposArchivo == NULL) {
        printf("No se pudo abrir el archivo equipos.txt\n");
        return;
    }

    FILE *resultadosArchivo = fopen("resultados.txt", "w");
    if (resultadosArchivo == NULL) {
        printf("No se pudo abrir el archivo resultados.txt\n");
        fclose(equiposArchivo);
        return;
    }

    char equipos[100][100];
    int numEquipos = 0;

    while (fscanf(equiposArchivo, "%s", equipos[numEquipos]) == 1) {
        numEquipos++;
    }

    for (int i = 0; i < numEquipos; i++) {
        for (int j = 0; j < numEquipos; j++) {
            if (i != j) {
                printf("Ingrese los goles para el partido entre %s y %s:\n", equipos[i], equipos[j]);
                int goles1, goles2;
                printf("%s: ", equipos[i]);
                scanf("%d", &goles1);
                printf("%s: ", equipos[j]);
                scanf("%d", &goles2);

                fprintf(resultadosArchivo, "%s,%s,%d,%d\n", equipos[i], equipos[j], goles1, goles2);
            }
        }
    }

    fclose(equiposArchivo);
    fclose(resultadosArchivo);
}

void generarResultadosAutomatico() {
    FILE *equiposArchivo = fopen("equipos.txt", "r");
    if (equiposArchivo == NULL) {
        printf("No se pudo abrir el archivo equipos.txt\n");
        return;
    }

    FILE *resultadosArchivo = fopen("resultados.txt", "w");
    if (resultadosArchivo == NULL) {
        printf("No se pudo abrir el archivo resultados.txt\n");
        fclose(equiposArchivo);
        return;
    }

    char equipos[100][100];
    int numEquipos = 0;

    while (fscanf(equiposArchivo, "%s", equipos[numEquipos]) == 1) {
        numEquipos++;
    }

    for (int i = 0; i < numEquipos; i++) {
        for (int j = 0; j < numEquipos; j++) {
            if (i != j) {
                int goles1 = rand() % 5;
                int goles2 = rand() % 5;

                fprintf(resultadosArchivo, "%s,%s,%d,%d\n", equipos[i], equipos[j], goles1, goles2);
            }
        }
    }

    fclose(equiposArchivo);
    fclose(resultadosArchivo);
}

