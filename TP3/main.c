#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    int option = 0;
    int r;
    int flag = 0;

    do
    {
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3. Alta de empleado.\n");
        printf("4. Modificar datos de empleado.\n");
        printf("5. Baja de empleado.\n");
        printf("6. Listar empleados.\n");
        printf("7. Ordenar empleados.\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir.\n");
        printf("Elija una opcion : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            r = controller_loadFromText("data.csv",listaEmpleados);
            if(r==0)
            {
                printf("\nDatos cargados a modo texto de forma exitosa.\n\n");
                flag = 1;
            }
            else
            {
                printf("\n\nNo se pudieron cargar los datos.\n\n");
            }
            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            printf("\nDatos cargados a modo binario de forma exitosa.\n\n");
            flag = 1;
            break;
        case 3:
            if(flag == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nLos datos no fueron cargados todavia.\n\n");
            }
            break;
        case 4:
            if(flag == 1)
            {
                r = controller_editEmployee(listaEmpleados);
                if(r==0)
                {
                    printf("\n\nModificacion exitosa.\n\n");
                }
                else if(r==-1)
                {
                    printf("\n\nNo se encontro al empleado.\n\n");
                }
                else
                {
                    printf("\n\nNo ha elegido ninguna opcion disponible.\n\n");
                }
            }
            else
            {
                printf("\n\nLos datos no fueron cargados todavia.\n\n");
            }

            break;
        case 5:
            if(flag == 1)
            {
                r = controller_removeEmployee(listaEmpleados);
                if(r==0)
                {
                    printf("\n\nBaja exitosa.\n\n");
                }
                else if(r==-1)
                {
                    printf("\n\nNo se encontro al empleado.\n\n");
                }
                else
                {
                    printf("\n\nAccion cancelada.\n\n");
                }
            }
            else
            {
                printf("\n\nLos datos no fueron cargados todavia.\n\n");
            }
            break;
        case 6:
            if(flag == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nLos datos no fueron cargados todavia.\n\n");
            }
            break;
        case 7:
            if(flag == 1)
            {
                r = controller_sortEmployee(listaEmpleados);
                if(r==0)
                {
                    printf("\n\nEl listado fue ordenado exitosamente.\n\n");
                }
                else
                {
                    printf("\n\nNo ha elegido una opcion disponible\n\n");
                }
            }
            else
            {
                 printf("\n\nLos datos no fueron cargados todavia.\n\n");
            }

            break;
        case 8:
            if(flag == 1)
            {
                controller_saveAsText("data.csv",listaEmpleados);
                printf("\n\nLos datos fueron guardados exitosamente.\n\n");
            }
            else
            {
                printf("\n\nLos datos no fueron cargados todavia.\n\n");
            }

            break;
        case 9:
             if(flag == 1)
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
                printf("\n\nLos datos fueron guardados exitosamente.\n\n");
            }
            else
            {
                printf("\n\nLos datos no fueron cargados todavia.\n\n");
            }
            break;

        case 10:
            break;
        default:
            printf("\nOpcion invalida.\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(option != 10);

    return 0;
}
