#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    int i;
    int r = -1;
    if((len > 0 && len < 1001) && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = TRUE;
        }
        r = 0;
    }
    return r;
}

int addEmployee(Employee* list, int len, int idNumber, char name[], char lastName[], float salary, int sector)
{

    int r = -1;
    int i;

    i = searchIsEmpty(list, len);

    if(i != -1)
    {
        strcpy(list[i].name,name);
        strcpy(list[i].lastName, lastName);
        list[i].sector = sector;
        list[i].salary = salary;
        list[i].isEmpty = FALSE;
        list[i].id = idNumber;
        r = 0;
    }
    return r;

}

int searchIsEmpty(Employee* list, int len)
{
    int i;
    int index= -1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==TRUE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int findEmployeeById(Employee* list, int len)
{
    int i;
    int r = -1;
    int idNumber;

    printf("\nIngrese el Id del empleado: ");
    scanf("%d", &idNumber);


    for(i=0; i<len; i++)
    {
        if(list[i].id == idNumber)
        {
            if(list[i].isEmpty == FALSE)
            {
                r = i;
                break;
            }

        }
    }
    return r;
}

int removeEmployee(Employee* list, int len)
{
    int r = -1;
    int i;
    char respuesta;

    printEmployees(list, len);
    i = findEmployeeById(list, len);
    if(i != -1)
    {
        printf("\n\nSeleccione s para confirmar la accion: ");
        respuesta = getche();
        if(respuesta == 's')
        {
            list[i].isEmpty = TRUE;
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

int modifyEmployee(Employee* list, int len)
{
    int i;
    int option;
    int r = -1;
    printEmployees(list, len);
    i = findEmployeeById(list, len);
    printf("\n\n�Que desea modificar?\n\n");
    printf("1. Nombre.\n");
    printf("2. Apellido.\n");
    printf("3. Salario.\n");
    printf("4. Sector.\n");
    printf("Elija una opcion : ");
    scanf("%d", &option);

    if(i != -1)
    {
        switch(option)
        {
        case 1:
            printf("\nIngrese el nombre del empleado : ");
            fflush(stdin);
            gets(list[i].name);
            r = 0;
            break;
        case 2:
            printf("\n\nIngrese el apellido del empleado : ");
            fflush(stdin);
            gets(list[i].lastName);
            r = 0;
            break;
        case 3:
            printf("\n\nIngrese el salario del empleado : ");
            scanf("%f", &list[i].salary);
            r = 0;
            break;
        case 4:
            printf("\n\nIngrese el sector del empleado : ");
            scanf("%d", &list[i].sector);
            r = 0;
            break;
        default:
            r = 1;
        }
    }
    return r;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmployee;
    int i;
    int j;
    int r = -1;

    if((len > 0 && len < 1001) && list != NULL)
    {
        if(order == 1)
        {
            for(i=0; i<len-1; i++) // For para ordenar por sector.
            {
                for(j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty == FALSE && list[i].sector > list[j].sector)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
            for(i=0; i<len-1; i++) // For para ordenar por apellido con los sectores ordenados.
            {
                for(j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty == FALSE && list[i].sector == list[j].sector)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName) > 0)
                        {
                            auxEmployee = list[i];
                            list[i] = list[j];
                            list[j] = auxEmployee;
                        }
                    }
                }
            }
        }
        else
        {
            for(i=0; i<len-1; i++) // For para ordenar por sector.
            {
                for(j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty == FALSE && list[i].sector < list[j].sector)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
            for(i=0; i<len-1; i++) // For para ordenar por apellido con los sectores ordenados.
            {
                for(j=i+1; j<len; j++)
                {
                    if(list[i].isEmpty == FALSE && list[i].sector == list[j].sector)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName) < 0)
                        {
                            auxEmployee = list[i];
                            list[i] = list[j];
                            list[j] = auxEmployee;
                        }
                    }
                }
            }
        }

        r = 0;
    }
    return r;
}

int printEmployees(Employee* list, int len)
{
    int i;
    int r = -1;
    printf("ID\tSECTOR\t\t\tNOMBRE\t\t\t\tAPELLIDO\tSALARIO\n");
    if((len > 0 && len < 1001) && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                printf("%04d\t%02d\t%22s\t\t%22s\t\t%f\n", list[i].id,list[i].sector,list[i].name,list[i].lastName,list[i].salary);
            }
        }
        r = 0;
    }

    return r;
}

int flagEmployee(Employee* list, int len)
{
    int r = -1;
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            r = 0;
            break;
        }
    }

    return r;
}

void menuEmployees(Employee* listEmployees, int len, int idNumber, char name[], char lastName[],float salary, int sector)
{
    int option;
    int r;
    float average;
    int employeesAverage;
    int order;


    do
    {
        printf("1. Dar de alta a un empleado.\n");
        printf("2. Modificar empleados por numero de Id.\n");
        printf("3. Dar de baja a un empleado.\n");
        printf("4. Informe de empleados.\n");
        printf("Elija una opcion: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            fflush(stdin);
            printf("\nIngrese el nombre del empleado : ");
            name = enterString(name);
            firstLetterMayus(name);
            r = onlyLetters(name);
            if(r==0)
            {
                printf("\nSolo se permiten letras.\n");
                break;
            }
            toLowerCase(name);
            fflush(stdin);
            printf("\n\nIngrese el apellido del empleado : ");
            lastName = enterString(lastName);
            firstLetterMayus(lastName);
            r = onlyLetters(lastName);
            if(r==0)
            {
                printf("Solo se permiten letras.\n");
                break;
            }
            toLowerCase(lastName);
            printf("\n\nIngrese el salario del empleado : ");
            salary = enterFloat(salary);
            printf("\n\nIngrese el sector del empleado : ");
            sector = enterInt(sector);
            if(r==0)
            {
                printf("Solo se permiten numeros en este campo.\n");
                fflush(stdin);
                break;
            }
            r = addEmployee(listEmployees, ELEMENTS, idNumber, name, lastName, salary, sector);
            if(r == 0)
            {
                idNumber ++;
                printf("\nEmpleado cargado exitosamente.\n\n");
            }
            else
            {
                printf("\nNo hay mas espacio.\n\n");
            }
            break;
        case 2:
            if(flagEmployee(listEmployees, ELEMENTS) == 0)
            {
                r = modifyEmployee(listEmployees, ELEMENTS);
                if(r == 0)
                {
                    printf("\n\nEmpleado modificado exitosamente. \n\n");
                }
                else if(r == 1)
                {
                    printf("\n\nNo ha elegido una accion valida.\n\n");
                }
                else
                {
                    printf("\n\nNo se encontro al empleado.\n\n");
                }
            }
            else
            {
                printf("\n\nNo hay ningun empleado activo.\n\n");
            }

            break;
        case 3:
            if(flagEmployee(listEmployees, ELEMENTS) == 0)
            {
                r = removeEmployee(listEmployees, ELEMENTS);
                if(r == 0)
                {
                    printf("\n\nEmpleado eliminado exitosamente.\n\n");
                }
                else if(r == -1)
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
                printf("\n\nNo hay ningun empleado activo.\n\n");
            }

            break;
        case 4:
            if(flagEmployee(listEmployees, ELEMENTS) == 0)
            {
                printf("\n\nElige lo que quieras informar.\n\n");
                printf("\n1.Listado de los empleados ordenados alfabeticamente por Apellido y Sector.");
                printf("\n2.Total y promedio de los salarios, y cuantos empleados superan el salario promedio.");
                printf("\nElija la opcion : ");
                scanf("%d", &option);
                switch(option)
                {
                case 1:
                    printf("Quiere ordenar de manera : \n");
                    printf("1.Ascendente.\n");
                    printf("2.Descendente.\n");
                    printf("Elija una opcion : ");
                    scanf("%d", &order);
                    r = sortEmployees(listEmployees, ELEMENTS, order);
                    if(r==0)
                    {
                        r = printEmployees(listEmployees, ELEMENTS);
                        if(r == 0)
                        {
                            printf("\n\nEmpleados ordenados y mostrados exitosamente.\n\n");
                        }
                        else
                        {
                            printf("\n\nNo se pudieron mostrar a los empleados.\n\n");
                        }
                    }
                    else
                    {
                        printf("\n\nNo se pudieron ordenar a los empleados.\n\n");
                    }
                    break;
                case 2:
                    average = averageSalary(listEmployees, ELEMENTS);
                    printf("\n\nEl promedio de los salarios es : %f", average);
                    employeesAverage = employeesWithMoreSalary(listEmployees, ELEMENTS, average);
                    if(employeesAverage == 1)
                    {
                        printf("\nSolamente un empleado supera el promedio salarial.\n\n");
                    }
                    else
                    {
                        printf("\nHay %d empleados que superan el promedio salarial.\n\n", employeesAverage);
                    }
                    break;
                }
            }
            else
            {
                printf("\n\nNo hay ningun empleado activo.\n\n");
            }

            break;
        }

        system("pause");
        system("cls");

    }
    while(option != 5);
}

int enterInt(int num1)
{
    scanf("%d", &num1);
    return num1;
}

float enterFloat(float num1)
{
    scanf("%f", &num1);
    return num1;
}

char* enterString(char* string1)
{
    fflush(stdin);
    gets(string1);
    return string1;
}

float averageSalary(Employee* list, int len)
{
    int i;
    float accum = 0;
    int count = 0;
    float average = 0;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            accum = accum + list[i].salary;
            count ++;
        }
    }

    average = accum / count;

    return average;
}

int employeesWithMoreSalary(Employee* list, int len, int avg)
{
    int i;
    int count = 0;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == FALSE && list[i].salary > avg)
        {
            count++;
        }
    }
    return count;
}

int onlyLetters(char string1[])
{
    int i;
    int largo;
    int r = -1;
    largo = strlen(string1);
    for(i=1; i<largo; i++)
    {
        if(((string1[i]<97 && string1[i]>90) || string1[i]>122) || string1[i]<65)
        {
            r = 0;
            return r;
        }
    }
    return r;
}

void toLowerCase(char string1[])
{
    int i;
    int largo;
    largo = strlen(string1);
    for(i=1; i<largo; i++)
    {
        if(string1[i]>64 && string1[i]<91)
        {
            string1[i] = string1[i]+32;
        }
    }
}

void firstLetterMayus(char string1[])
{
    if(string1[0] > 96 && string1[0] < 123)
    {
        string1[0] = string1[0] - 32;
    }
}

