#include "Employee.h"
#include <malloc.h>


Employee* employee_new()
{
    return (Employee*)(malloc(sizeof(Employee)));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* oneEmployee = employee_new();
    if(oneEmployee!=NULL)
    {
        employee_setId(oneEmployee,atoi(idStr));
        employee_setNombre(oneEmployee,nombreStr);
        employee_setHorasTrabajadas(oneEmployee,atoi(horasTrabajadasStr));
    }
    return oneEmployee;
}

int employee_setId(Employee* this,int id)
{
    int r = -1;
    if(this != NULL && id>0)
    {
        this->id=id;
        r = 0;
    }
    return r;
}

int employee_getId(Employee* this,int* id)
{
    if(this != NULL)
    {
        *id = this->id;
    }
    return *id;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int r = -1;
    if(this != NULL && nombre>0)
    {
        strcpy(this->nombre,nombre);
        r = 0;
    }
    return r;
}

int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
    }
    return nombre;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r = -1;
    if(this != NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        r = 0;
    }
    return r;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
    }
    return *horasTrabajadas;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int r = -1;
    if(this != NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        r = 0;
    }
    return r;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL)
    {
        *sueldo = this->sueldo;
    }
    return  *sueldo;
}

int comparaPorNombre(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return strcmp(empleado1->nombre,empleado2->nombre);

}

int employee_findById(Employee* listEmployees,LinkedList* pArrayListEmployee)
{
    int i;
    int idEmployee;
    int id;
    int r = -1;
    printf("Ingrese el ID del empleado : ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
       listEmployees = ll_get(pArrayListEmployee,i);
       employee_getId(listEmployees,&idEmployee);
       if(idEmployee==id)
       {
           return i;
       }
    }
    return r;
}

int comparaPorSueldosAscendente(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return (empleado1->sueldo > empleado2->sueldo);
}

int comparaPorSueldosDescendente(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return (empleado1->sueldo < empleado2->sueldo);
}

int comparaPorHorasAscendente(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return (empleado1->horasTrabajadas > empleado2->horasTrabajadas);
}

int comparaPorHorasDescendente(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return (empleado1->horasTrabajadas < empleado2->horasTrabajadas);
}

void employee_showOneEmployee(LinkedList* pArrayListEmployee,int index)
{
    Employee* aux;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];

    aux = (Employee*)ll_get(pArrayListEmployee, index);
    employee_getId(aux, &id);
    employee_getNombre(aux,&nombre);
    employee_getSueldo(aux,&sueldo);
    employee_getHorasTrabajadas(aux, &horasTrabajadas);
    printf("%d--%s--%d--%d\n",id,nombre,sueldo,horasTrabajadas);

}
