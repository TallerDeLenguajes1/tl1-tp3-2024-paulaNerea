#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *nombres[5]; //vector de 5 punteros 
    char *buff; //var aux
    buff= (char *) malloc(100*sizeof(char)); //reservo memoria para la var aux

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d: \n", i+1);
        gets(buff); //guardo el nombre en var aux

        nombres[i] = (char *)malloc((strlen(buff)+1) * sizeof(char)); //reservo memoria para guardar el avlor de var aux en vector 
        strcpy(nombres[i], buff);
        
    }
    free(buff);

    printf("Nombres Ingresados: \n");
    for (int i = 0; i < 5; i++) {
        puts(nombres[i]);
    }

    for (int i = 0; i < 5; i++) {
        free(nombres[i]);
    }
    
    return 0;
}