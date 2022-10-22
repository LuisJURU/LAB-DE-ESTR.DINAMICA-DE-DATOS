#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Nodo
{

    int dato;
    struct Nodo*siguiente;

}Nodo;

Nodo* primero = NULL;
Nodo* ultimo = NULL;

void InsertarNodo();
void BuscarNodo();
void EliminarNodo();
void DesplegarCola();

int main ()
{

    int opcMenu = 0;
    do
    {
        printf("\n|-------------------------------------|");
        printf("\n|               * COLA *              |");
        printf("\n|-------------------|-----------------|");
        printf("\n| 1. Insertar       | 4. Desplegar    |");
        printf("\n| 2. Buscar         | 5. Salir        |");
        printf("\n| 3. Eliminar       |                 |");
        printf("\n|-------------------|-----------------|");
        printf("\n\n Escoja una Opcion: ");
        scanf("%d", &opcMenu);

        switch(opcMenu)
        {

        case 1:
            system("CLS");
            printf("\n\n INSERTAR NODO EN LA COLA \n\n");
            InsertarNodo();
            break;
        case 2:
            system("CLS");
            printf("\n\n BUSCAR UN NODO EN LA COLA \n\n");
            BuscarNodo();
            break;
        case 3:
            system("CLS");
            printf("\n\n ELIMINAR UN NODO DE LA COLA \n\n");
            EliminarNodo();
            break;
        case 4:
            printf("\n\n DESPLEGAR COLA DE NODOS \n\n");
            DesplegarCola();
            break;
        case 5:
            system("CLS");
            printf("\n\n El programa finalizo... \n\n");
            break;
        default:
            printf("\n\n Opcion Invalida, Intentelo nuevamente \n\n");
        }

    }while(opcMenu != 5);
    return 0;
}

void InsertarNodo()
{

    Nodo* Nuevo = (Nodo*) malloc(sizeof(Nodo));
    printf("Ingrese el dato que tendra el nuevo Nodo: ");
    scanf("%d", &Nuevo->dato);
    if(primero==NULL)
    {
        primero = Nuevo;
        primero ->siguiente = NULL;
        ultimo = Nuevo;
    }else
    {

        ultimo->siguiente = Nuevo;
        Nuevo->siguiente = NULL;
        ultimo = Nuevo;

    }
    printf("\nEl Nodo a sido ingresado correctamente\n\n");

}


void BuscarNodo()
{

    Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
    actual = primero;
    int Nodobuscado=0, Encontrado=0;
    printf("Ingrese el valor del Nodo a encontrar: ");
    scanf("%d", &Nodobuscado);
    if(primero != NULL)
    {

        while(actual != NULL && Encontrado !=1)
        {

            if(actual->dato == Encontrado)
            {

                printf("\nNodo con el dato (%d) Encontrado\n\n", Nodobuscado);
                Encontrado = 1;

            }
            actual = actual->siguiente;

        }
        if(Encontrado == 0)
        {

            printf("\n El Nodo no fue encontrado\n\n");

        }

    }else
    {

        printf("\n La Cola no existe\n\n");

    }


}

void EliminarNodo()
{


    Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
    actual = primero;
    Nodo* anterior = (Nodo*) malloc(sizeof(Nodo));
    anterior = NULL;
    int Nodobuscado=0, Encontrado=0;
    printf("Ingrese el valor del Nodo a Eliminar: ");
    scanf("%d", &Nodobuscado);
    if(primero != NULL)
    {

        while(actual != NULL && Encontrado != 1){

            if(actual->dato == Encontrado){
                if(actual == primero){

                    primero = primero->siguiente;

                }else if(actual == ultimo){

                    anterior->siguiente = NULL;
                    ultimo = anterior;

                }else{

                    anterior->siguiente = actual->siguiente;

                }
                printf("\n El Nodo se a Eliminado con Exito\n\n");
                Encontrado = 1;

            }
            anterior = actual;
            actual = actual->siguiente;
        }
        if(Encontrado = 0){

            printf("\ El Nodo no se a Encontrado\n\n");

        }else{

            free(anterior);

        }

    }else{

        printf("\n La Cola no Existe\n\n");

    }
}

void DesplegarCola()
{

    Nodo* actual = (Nodo*) malloc(sizeof(Nodo));
    actual = primero;
    if(primero != NULL)
    {

        while(actual != NULL)
        {

            printf("\n %d", actual->dato);
            actual = actual->siguiente;

        }

    }else
    {

        printf("\n La Cola no existe\n\n");

    }

}
