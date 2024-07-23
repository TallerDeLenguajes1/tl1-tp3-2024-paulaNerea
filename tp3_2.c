#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarMatriz(int matriz[5][12]);
void muestraMatriz(int matriz[5][12]);
void promedio(int matriz [5][12]);
void maxmin(int matriz [5][12]);

int main(){
    int matriz[5][12];

    srand(time(NULL));
    printf("...Cargando Matriz...\n");
    cargarMatriz(matriz);
    printf("...Mostrando Matriz...\n");
    muestraMatriz(matriz);
    printf("...Calculando promedio de ganancias por año...\n");
    promedio(matriz);
    printf("...Valores Max y Min obrenidos...\n");
    maxmin(matriz);

    return 0;
}

void cargarMatriz(int matriz[5][12])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000; //entre y 10000 50000
        }
    }
    
}

void muestraMatriz(int matriz[5][12])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("matriz[%d][%d] = %d\n", i + 1, j + 1, matriz[i][j]); 
        }
    }
    
}

void promedio(int matriz[5][12])
{
    float promedio;
    for (int i = 0; i < 5; i++)
    {
        int contador = 0;
        for (int j = 0; j < 12; j++)
        {
            contador =  contador + matriz[i][j];
        }
        promedio = (float)contador/12;
        printf("Anio %d = %.2f \n", i+1, promedio);
    }
}

void maxmin(int matriz[5][12])
{
    int mayor = 0, anioMax, mesMax, menor = 50001, anioMin, mesMin;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matriz[i][j] > mayor)
            {
                mayor = matriz[i][j];
                anioMax = i;
                mesMax = j;
            }
            
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
                anioMin = i;
                mesMin = j;
            }
        }
    }
    printf("Valor Max = %d - Mes %d, Anio %d  \n", mayor, mesMax + 1, anioMax + 1);
    printf("Valor Min = %d - Mes %d, Anio %d  \n", menor, mesMin + 1, anioMin + 1);
}
