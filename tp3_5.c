#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char **nombres; 
    char *buff; 
    buff= (char *) malloc(100*sizeof(char)); 

    int cantNombres;
    printf("Ingrese la cantidad de Nombres: ");
    scanf("%d", &cantNombres);
    fflush(stdin);

    nombres = (char **)malloc(cantNombres * sizeof(char *));

    for (int i = 0; i < cantNombres; i++)
    {
        printf("Ingrese el nombre %d: \n", i+1);
        gets(buff); 
        nombres[i] = (char *)malloc((strlen(buff)+1) * sizeof(char));
        strcpy(nombres[i], buff);
        
    }
    free(buff);

    printf("Nombres Ingresados: \n");
    for (int i = 0; i < cantNombres; i++) {
        puts(nombres[i]);
    }

    for (int i = 0; i < cantNombres; i++) {
        free(nombres[i]);
    }
    
    return 0;
}