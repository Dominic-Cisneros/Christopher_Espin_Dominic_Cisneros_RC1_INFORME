#include <stdio.h>
 
int main() {
    int estudiantes;
    float notas[100][3];
    float promedio, suma;
    int i, j;
    float maxEst, minEst;
    float maxAsig, minAsig;
 
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &estudiantes);
 
    for (i = 0; i < estudiantes; i++) {
        printf("\nEstudiante %d\n", i + 1);
        suma = 0;
        for (j = 0; j < 3; j++) {
            printf("Ingrese la nota de la asignatura %d: ", j + 1);
            scanf("%f", &notas[i][j]);
            while (notas[i][j] < 0 || notas[i][j] > 10) {
                printf("Nota invalida. Ingrese nuevamente (0-10): ");
                scanf("%f", &notas[i][j]);
            }
            suma += notas[i][j];
        }
        promedio = suma / 3;
        maxEst = notas[i][0]; minEst = notas[i][0];
        for (j = 1; j < 3; j++) {
            if (notas[i][j] > maxEst) maxEst = notas[i][j];
            if (notas[i][j] < minEst) minEst = notas[i][j];
        }
        printf("Promedio del estudiante %d: %.2f\n", i + 1, promedio);
        printf("Nota maxima: %.2f | Nota minima: %.2f\n", maxEst, minEst);
    }
 
    printf("\n Resultados por asignatura \n");
    for (j = 0; j < 3; j++) {
        suma = 0; maxAsig = notas[0][j]; minAsig = notas[0][j];
        int aprobados = 0, reprobados = 0;
        for (i = 0; i < estudiantes; i++) {
            suma += notas[i][j];
            if (notas[i][j] > maxAsig) maxAsig = notas[i][j];
            if (notas[i][j] < minAsig) minAsig = notas[i][j];
            if (notas[i][j] >= 6) aprobados++;
            else reprobados++;
        }
        float promedioAsig = suma / estudiantes;
        printf("\nAsignatura %d:\n", j + 1);
        printf("  Promedio   : %.2f\n", promedioAsig);
        printf("  Nota maxima: %.2f\n", maxAsig);
        printf("  Nota minima: %.2f\n", minAsig);
        printf("  Aprobados  : %d\n", aprobados);
        printf("  Reprobados : %d\n", reprobados);
    }
    return 0;
}
