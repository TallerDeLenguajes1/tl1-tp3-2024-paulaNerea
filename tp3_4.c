#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas", "Snack","Cigarrillos","Caramelos","Bebidas"};

struct{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} typedef Cliente;

void cargarProductos(Cliente *cliente, int cant);
float totalProdu(Producto produ);
void mostrar(Cliente *cliente, int cant);

int main(){
    int n;
    printf("Ingrese la cantidad de clientes: \n");
    scanf("%d", &n);
    fflush(stdin);

    Cliente *clientes;
    clientes = (Cliente *)malloc(n * sizeof(Cliente));

    cargarProductos(clientes, n);
    mostrar(clientes, n);
    
    //libero memoria
    for (int i = 0; i < n; i++) {
        free(clientes[i].NombreCliente); // Libero para el nombre del cliente
        
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            free(clientes[i].Productos[j].TipoProducto); // Libero para el tipo de producto
        }
        free(clientes[i].Productos); // Libero para todos los productos
    }
    free(clientes); // Liberar memoria para los clientes
    

    return 0;
}

void cargarProductos(Cliente *cliente, int cant)
{
    srand(time(NULL));
    char *buff; //var aux para guardar nombre
    buff= (char *) malloc(100*sizeof(char));

    for (int i = 0; i < cant; i++)
    {
        printf("\n=====> CLIENTE[%d]:\n", i + 1);
        cliente[i].ClienteID = i;

        printf("Ingrese el nombre del cliente: \n");
        gets(buff); 
        cliente[i].NombreCliente = (char *)malloc((strlen(buff)+1) * sizeof(char));
        strcpy(cliente[i].NombreCliente, buff);

        
        cliente[i].CantidadProductosAPedir = rand() % 5 + 1; //max de 5 clientes
        cliente[i].Productos = malloc(cliente[i].CantidadProductosAPedir * sizeof(Producto)); //creo el arreglo
        for (int j = 0; j < cliente[i].CantidadProductosAPedir; j++)
        {
            cliente[i].Productos[j].ProductoID = j;
            cliente[i].Productos[j].Cantidad = rand() % 10 + 1; //max de 10 productos por clientes
             
            char *aux = TiposProductos[rand() % 5]; //se elige aleatoriamente un indice del arreglo dado, no necesito hacer malloc a aux
            cliente[i].Productos[j].TipoProducto = (char *) malloc ((strlen(aux)+1)*sizeof(char)); //guardo memoria para cada tipo
            strcpy(cliente[i].Productos[j].TipoProducto, aux);

            cliente[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
        }
    }

    free(buff);
}

float totalProdu(Producto produ)
{
    float totalProdu;
    totalProdu = produ.Cantidad * produ.PrecioUnitario;
    return totalProdu;
}

void mostrar(Cliente *cliente, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("\n=====> CLIENTE[%d]:\n", i + 1);
        printf("Nombre del Cliente: %s\n", cliente[i].NombreCliente);
        printf("Cantidad de Productos que pidio: %d\n", cliente[i].CantidadProductosAPedir);
        for (int j = 0; j < cliente[i].CantidadProductosAPedir; j++)
        {
            printf("==> Producto [%d] \n", j + 1);
            printf("Cantidad: %d unidades \n", cliente[i].Productos[j].Cantidad);
            printf("Tipo: %s \n", cliente[i].Productos[j].TipoProducto);
            printf("Precio Unitario: $%.2f \n", cliente[i].Productos[j].PrecioUnitario);
            printf("Total: $%.2f \n", totalProdu(cliente[i].Productos[j]));
            printf("========================================\n");

        }
    }
}

