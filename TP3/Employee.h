#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int comparaPorNombre(void* , void* );
int comparaPorSueldosAscendente(void* , void*);
int comparaPorSueldosDescendente(void* , void*);
int comparaPorHorasDescendente(void* , void*);
int comparaPorHorasAscendente(void* , void*);
int employee_findById(Employee*,LinkedList*);
void employee_showOneEmployee(LinkedList*,int);

#endif // employee_H_INCLUDED
