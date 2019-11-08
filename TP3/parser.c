#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* listEmployees;
    int r = 0;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    if(pFile == NULL)
    {
        return -1;
    }
    do
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        listEmployees = employee_newParametros(id,nombre,horasTrabajadas);
        employee_setSueldo(listEmployees,atoi(sueldo));
        ll_add(pArrayListEmployee, listEmployees);

    }
    while(!feof(pFile));

    return r;
}





/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* listEmployees;
    if(pFile == NULL)
    {
        return -1;
    }
    while(!feof(pFile))
    {
        listEmployees = employee_new();
        fread(listEmployees,sizeof(Employee),1,pFile);
        if(feof(pFile))
        {
            break;
        }
        ll_add(pArrayListEmployee, listEmployees);
    }

    return 1;
}
