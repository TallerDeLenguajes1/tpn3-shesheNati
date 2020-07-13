#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct 
{
    int ProductoID; 
    int Cantidad; 
    char *TipoProducto; 
    float PrecioUnitario; 
}S_Producto;

typedef struct
{
    int ClienteID; 
    char *NombreCliente; 
    int CantidadProductoAPedir; 
    S_Producto *Productos; 
}S_Cliente;


/*********PROTOTIPO***************/
void AltaCliente( S_Cliente *cliente, int cantC);
void AltaProducto(S_Producto *prod, int cantP);
int CostoDeProducto(S_Producto *prod);
void MostrarProductos(S_Producto *prod,int cantP);
void MuestraEntrevistados(S_Cliente *cliente, int canC);



/******** PROGRAMA PRINCIPAL******/
int main()
{
    srand(time(NULL));
    int cant_clientes;
    char *nombre, n[100];
    S_Cliente *nuevo; 


    printf("Ingrese la cantidad de clientes:");
    scanf("%d",&cant_clientes);

    if(cant_clientes > 5)
    {
         printf("Supero la cantidad permitida de cliente ingrese una inferior a 6");
         scanf("%d",&cant_clientes);
    }
    
    nuevo = (S_Cliente *)malloc(sizeof(S_Cliente) * cant_clientes);
    AltaCliente(nuevo,cant_clientes);
    MuestraEntrevistados(nuevo, cant_clientes);
   

    scanf(" %c");
    return 0;
}

/******************FUNCIONES *************************/

void AltaCliente( S_Cliente *cliente, int cantC)
{
    char nombre[100];
    for( int i = 0; i < cantC; i++)
    {
        
        cliente[i].ClienteID = i;
        printf("Ingrese el nombre del cliente a agregar ID %d:", i);
        scanf("%s", nombre);
        cliente[i].NombreCliente = (char *) malloc(sizeof(char) * (strlen(nombre) + 1));
        strcpy(cliente[i].NombreCliente, nombre);
        cliente[i].CantidadProductoAPedir = rand()% 6 + 1;
        cliente[i].Productos = (S_Producto *)malloc(sizeof(S_Producto) * (cliente[i].CantidadProductoAPedir));
        AltaProducto(cliente[i].Productos, cliente[i].CantidadProductoAPedir);
    }
}


void AltaProducto(S_Producto *prod, int cantP)
{
    char *aux;
    int aleatorio;
    for (int i = 0; i < cantP; i++)
    {
        aleatorio = rand() % 6 + 1 ;
        prod[i].ProductoID = aleatorio;
        prod[i].Cantidad= rand()% 11 + 1;
        aux = TiposProductos[aleatorio];

        prod[i].TipoProducto = (char *)malloc(sizeof(char) * (strlen(aux)+ 1));
        strcpy(prod[i].TipoProducto, aux);
        prod[i].PrecioUnitario = rand()% 101 + 10;
    }
}




int CostoDeProducto(S_Producto *prod)
{
    float aux_total;

    aux_total = (prod->Cantidad) * (prod ->PrecioUnitario);
    
    return aux_total;
}

void MostrarProductos(S_Producto *prod,int cantP)
{
    int aux_total = 0;
    for(int i = 0; i < cantP; i++)
    {
        printf("ID %d  del producto | %d\n", i + 1, prod[i].ProductoID);
        printf("Cantidad: %d\n", prod[i].Cantidad);
        printf("Tipo de producto: %s\n", prod[i].TipoProducto);
        printf("Precio unitario: %.2f\n\n", prod[i].PrecioUnitario);
        aux_total = aux_total + CostoDeProducto(prod + i);
    }
    printf("Costo total a pagar: $ %d\n\n", aux_total);
}



void MuestraEntrevistados(S_Cliente *cliente, int cantC)
{
     for (int i = 0; i < cantC; i++)
    {
        printf("\n________________________________________________");

        printf("\n\nID del cliente %d | %d\n",i+1,i);
        printf("Nombre del cliente: %s\n",cliente[i].NombreCliente);
        printf("Cantidad de los productos a pedir: %d\n\n",cliente[i].CantidadProductoAPedir);

        MostrarProductos(cliente[i].Productos,cliente[i].CantidadProductoAPedir); //Funcion para mostrar productos

        printf("__________________________________________________");
    }

}