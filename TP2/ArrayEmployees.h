#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define ELEMENTS 1000


struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

int initEmployees(Employee*, int);
int addEmployee(Employee*, int, int, char[], char[],float , int);
int findEmployeeById(Employee*, int);
int removeEmployee(Employee*, int);
int sortEmployees(Employee*, int);
int printEmployees(Employee*, int);
int searchIsEmpty(Employee*, int);
int modifyEmployee(Employee*, int);
int flagEmployee(Employee*, int);
void menuEmployees(Employee*, int, int, char[], char[],float , int);
int enterInt(int);
float enterFloat(float);
char* enterString(char*);
float averageSalary(Employee*, int);
int employeesWithMoreSalary(Employee*, int, int);








