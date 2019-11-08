#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <conio.h>
#include "parser.h"
#include "Validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int r;
    FILE* pArchivo;
    pArchivo = fopen(path,"r");
    r = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
    fclose(pArchivo);

    return r;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"rb");
    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    fclose(pArchivo);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* oneEmployee;
    Employee* aux;
    int r;
    char nombre[50];
    int sueldo;
    int horasTrabajadas;
    int largo;
    int id;
    oneEmployee = employee_new();

    largo = ll_len(pArrayListEmployee);
    aux = (Employee*)ll_get(pArrayListEmployee, largo-1);
    employee_getId(aux,&id);
    employee_setId(oneEmployee, id+1);


    printf("Ingrese el nombre del empleado : ");
    enterString(nombre);
    r = soloLetras(nombre);
    while(r==-1)
    {
        printf("Solo se permiten letras. Reingrese el nombre del empleado : ");
        enterString(nombre);
        r = soloLetras(nombre);
    }
    employee_setNombre(oneEmployee,nombre);

    horasTrabajadas = enterInt("Ingrese las horas trabajadas del empleado : ");
    r = soloPositivos(horasTrabajadas);
    while(r==-1)
    {
        horasTrabajadas = enterInt("No puede tener horas trabajadas en negativo. Reingrese las horas trabajadas del empleado : ");
        r = soloPositivos(horasTrabajadas);
    }

    employee_setHorasTrabajadas(oneEmployee,horasTrabajadas);

    sueldo = enterInt("Ingrese el sueldo del empleado : ");
    r = soloPositivos(sueldo);
    while(r==-1)
    {
        sueldo = enterInt("No puede tener sueldo negativo. Reingrese el sueldo del empleado : ");
        r = soloPositivos(sueldo);
    }
    employee_setSueldo(oneEmployee,sueldo);

    ll_add(pArrayListEmployee, oneEmployee);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    Employee* oneEmployee;
    char nombre[50];
    int r = -1;
    int index;
    int horasTrabajadas;
    int sueldo;
    index = employee_findById(oneEmployee,pArrayListEmployee);
    if(index!=-1)
    {
        employee_showOneEmployee(pArrayListEmployee,index);
        oneEmployee = (Employee*)ll_get(pArrayListEmployee, index);
        printf("Que desea modificar.\n");
        printf("1.Nombre.\n");
        printf("2.Horas trabajadas.\n");
        printf("3.Sueldo.\n");
        printf("Ingrese una opcion : ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre : ");
            enterString(nombre);
            r = soloLetras(nombre);
            while(r==-1)
            {
                printf("Solo se permiten letras. Reingrese el nombre : ");
                enterString(nombre);
                r = soloLetras(nombre);
            }
            employee_setNombre(oneEmployee,nombre);
            r = 0;
            break;
        case 2:
            horasTrabajadas = enterInt("Ingrese las nuevas horas trabajadas del empleado : ");
            r = soloPositivos(horasTrabajadas);
            while(r==-1)
            {
                horasTrabajadas = enterInt("No puede tener horas trabajadas en negativo. Reingrese las horas trabajadas : ");
                r = soloPositivos(horasTrabajadas);
            }
            employee_setHorasTrabajadas(oneEmployee,horasTrabajadas);
            r = 0;
            break;
        case 3:
            sueldo = enterInt("Ingrese el nuevo sueldo del empleado : ");
            r = soloPositivos(sueldo);
            while(r==-1)
            {
                sueldo = enterInt("No puede tener el sueldo en negativo. Reingrese el sueldo del empleado : ");
                r = soloPositivos(sueldo);
            }
            employee_setSueldo(oneEmployee,sueldo);
            r = 0;
            break;
        default:
            r = 1;
            break;
        }
    }


    return r;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* oneEmployee;
    int r = -1;
    int index;
    char respuesta;
    index = employee_findById(oneEmployee,pArrayListEmployee);
    if(index!=-1)
    {
        employee_showOneEmployee(pArrayListEmployee,index);
        oneEmployee = (Employee*)ll_get(pArrayListEmployee, index);
        printf("Esta seguro que desea eliminar a este empleado? Presione s para confirmar : ");
        respuesta = getche();
        if(respuesta!='s')
        {
            return 1;
        }
        ll_remove(pArrayListEmployee,index);
        r = 0;
    }
    return r;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    for(i=1; i<ll_len(pArrayListEmployee); i++)
    {
        employee_showOneEmployee(pArrayListEmployee,i);
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int r = 0;
    printf("\n\nBajo que criterio quiere ordenar a los empleados?\n");
    printf("1.Nombres\n");
    printf("2.Sueldos\n");
    printf("3.Horas trabajadas\n");
    printf("\nElija una opcion : ");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        printf("Orden ascendente o descendente?\n");
        printf("1.Ascendente.\n");
        printf("2.Descendente.\n");
        printf("\nElija una opcion : ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorNombre,1);
            break;
        case 2:
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorNombre,0);
            break;
        }
        break;
    case 2:
        printf("Orden ascendente o descendente?\n");
        printf("1.Ascendente.\n");
        printf("2.Descendente.\n");
        printf("\nElija una opcion : ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorSueldosAscendente,1);
            break;
        case 2:
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorSueldosDescendente,1);
            break;
        }
        break;
    case 3:
        printf("Orden ascendente o descendente?\n");
        printf("1.Ascendente.\n");
        printf("2.Descendente.\n");
        printf("\nElija una opcion : ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorHorasAscendente,1);
            break;
        case 2:
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorHorasDescendente,1);
            break;
        }
        break;
    default:
        r = 1;
        break;
    }

    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* listEmployees;
    int r = 0;
    int i;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];
    pFile = fopen(path, "w");
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        listEmployees = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(listEmployees, &id);
        employee_getNombre(listEmployees,&nombre);
        employee_getSueldo(listEmployees,&sueldo);
        employee_getHorasTrabajadas(listEmployees, &horasTrabajadas);
        fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,sueldo,horasTrabajadas);
    }

    fclose(pFile);
    return r;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* listEmployees;
    int r = 0;
    int i;
    pFile = fopen(path, "wb");
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {

        listEmployees = (Employee*)ll_get(pArrayListEmployee,i);
        //employee_showOneEmployee(pArrayListEmployee, i);
        fwrite(listEmployees,sizeof(Employee),1,pFile);
    }

    fclose(pFile);
    return r;
}

