#include <stdio.h>

int main() {

    int estudiantes;
    float notas[100][3];
    float promedio;
    float suma = 0;
    int i, j;
    int aprobados = 0;
    float maxEst, minEst;
    float maxAsig, minAsig;

    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &estudiantes); 

    for(i = 0; i < estudiantes; i++) { 

        printf("\nEstudiante %d\n", i + 1);

        for(j = 0; j < 3; j++) { 

            printf("Ingrese la nota de la asignatura %d: ", j + 1);
            scanf("%f", &notas[i][j]);

            while(notas[i][j] < 0 || notas[i][j] > 10) { 

                printf("Nota invalida. Ingrese nuevamente (0-10): ");
                scanf("%f", &notas[i][j]);
            }

            suma += notas[i][j]; 
        }

        promedio = suma / 3; 

        maxEst = notas[i][0];
        minEst = notas[i][0];
        for(j = 1; j < 3; j++) { 

            if(notas[i][j] > maxEst) {
                maxEst = notas[i][j];
            }

            if(notas[i][j] < minEst) {
                minEst = notas[i][j];
            }
        }
        printf("Promedio del estudiante: %.2f\n", promedio); 
        printf("Nota maxima del estudiante: %.2f\n", maxEst);
        printf("Nota minima del estudiante: %.2f\n", minEst);

        if(promedio >= 6)
        {
            aprobados++;
        }
    }
    printf("\n---Resultados por asignatura---\n");
    for(j = 0; j < 3; j++) { 

        float sumaAsig = 0;
        maxAsig = notas[0][j];
        minAsig = notas[0][j];

        for(i = 0; i < estudiantes; i++) { 

            sumaAsig += notas[i][j];

            if(notas[i][j] > maxAsig) {
                maxAsig = notas[i][j];
            }

            if(notas[i][j] < minAsig) {
                minAsig = notas[i][j];
            }
        }

        printf("Asignatura %d - Promedio: %.2f, Max: %.2f, Min: %.2f\n", j + 1, sumaAsig / estudiantes, maxAsig, minAsig);
    }
    printf("\nTotal aprobados: %d\n", aprobados);

    return 0;
}