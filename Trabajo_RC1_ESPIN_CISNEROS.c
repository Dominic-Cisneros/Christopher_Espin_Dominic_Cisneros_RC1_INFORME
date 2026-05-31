#include <stdio.h>

int main() {

    int estudiantes;
    float notas[100][3];
    float promedio;
    float suma = 0;
    int i, j;
    int aprobados = 0;

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

        printf("Promedio del estudiante: %.2f\n", promedio); 

        if(promedio >= 6)
        {
            aprobados++;
        }
    }

    printf("\nTotal aprobados: %d\n", aprobados);

    return 0;
}