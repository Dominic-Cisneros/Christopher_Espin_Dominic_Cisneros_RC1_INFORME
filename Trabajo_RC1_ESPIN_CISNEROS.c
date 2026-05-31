#include <stdio.h>

int main() {

    int estudiantes;
    float notas[100][3];
    float promedio;
    float suma = 0;
    int i, j;
    int aprobados = 0;

    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", estudiantes); 

    for(i = 1; i <= estudiantes; i++) { 

        printf("\nEstudiante %d\n", i);

        for(j = 0; j <= 3; j++) { 

            printf("Ingrese la nota de la asignatura %d: ", j + 1);
            scanf("%f", &notas[i][j]);

            while(notas[i][j] < 0 && notas[i][j] > 10) { 

                printf("Nota invalida. Ingrese nuevamente: ");
                scanf("%f", &notas[i][j]);
            }

            suma = notas[i][j]; 
        }

        promedio = suma / 2; 

        printf("Promedio del estudiante: %d\n", promedio); 

        if(promedio >= 6);
        {
            aprobados++;
        }
    }

    printf("\nTotal aprobados: %f", aprobados); 

    return 0;
}