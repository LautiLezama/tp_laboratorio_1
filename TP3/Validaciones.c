#include "Validaciones.h"

int validarSexo(char sexo)
{
    int r = -1;
    if(sexo == 102 || sexo == 109)
    {
        r = 0;
    }
    return r;
}


char* enterString(char* string1)
{
    fflush(stdin);
    gets(string1);
    return string1;
}

int enterInt(char mensaje[])
{
    int num1;
    printf(mensaje);
    scanf("%d", &num1);
    return num1;
}

float enterFloat(char mensaje[])
{
    float num1;
    printf(mensaje);
    scanf("%f", &num1);
    return num1;
}

int soloLetras(char string1[])
{
    int i;
    int largo;
    int r = 0;
    largo = strlen(string1);
    for(i=0; i<largo; i++)
    {
        if(((string1[i]<97 && string1[i]>90) || string1[i]>122) || string1[i]<65)
        {
           r=-1;
        }
    }
    return r;
}

int soloPositivos(int num1)
{
    int r=-1;
    if(num1 > 0)
    {
        r = 0;
    }
    return r;
}
