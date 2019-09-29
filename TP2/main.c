#include "ArrayEmployees.h"


int main()
{
    Employee listEmployees[ELEMENTS];
    char name[51];
    char lastName[51];
    float salary = 0;
    int sector =0;
    int idNumber = 1;

    if(initEmployees(listEmployees, ELEMENTS) == 0)
    {
        menuEmployees(listEmployees, ELEMENTS, idNumber, name, lastName, salary, sector);
    }
    else
    {
        printf("Hubo un error al ingresar al menu.");
    }
}
