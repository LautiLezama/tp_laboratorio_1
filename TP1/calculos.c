
#include "calculos.h"

float pedirNum(char msj[], float num1)
{
    printf("%s", msj);
    scanf("%f", &num1);
    return num1;
}

float sumar(float num1, float num2)
{
    float total;
    total = num1 + num2;
    return total;
}

float restar(float num1, float num2)
{
    float total;
    total = num1 - num2;
    return total;
}

float dividir(float num1, float num2)
{
    float total;
    total = num1 / num2;
    return total;
}

float multiplicar(float num1, float num2)
{
    float total;
    total = num1 * num2;
    return total;
}

float factorial(float num1)
{
    float factorial = 1;

    for(int contador = num1; contador > 0; contador --)
    {
        factorial = factorial * contador;
    }
    return factorial;
}

void calcular(float num1, float num2)
{

    float resultadoS;
    float resultadoR;
    float resultadoD;
    float resultadoM;
    float resultadoF1;
    float resultadoF2;
    int menu;
    int flagWhile = 0;
    int flagNum1 = 0;
    int flagNum2 = 0;

    while(flagWhile == 0)
    {

        printf("\nIngrese 1 para ingresar o modificar el primer operando. \nIngrese 2 para ingresar o modificar el segundo operando.");
        printf("\nIngrese 3 para calcular todas las operaciones. \nIngrese 4 para informar los resultados. \nIngrese 5 para salir.\n");
        scanf( "%d", &menu);
        switch(menu)
        {
        case 1:
            num1 = pedirNum("\nIngrese el primer numero : ",num1);
            flagNum1 = 1;
            break;
        case 2:
            num2 = pedirNum("\nIngrese el segundo numero : ",num2);
            flagNum2 = 1;
            break;
        case 3:
            if(flagNum1 == 0 || flagNum2 == 0)
            {
                printf("\nAl menos uno de los 2 numeros no fue ingresado. Ingrese los 2 numeros para calcular.\n");
            }
            else
            {
                resultadoS = sumar(num1, num2);
                resultadoR = restar(num1, num2);
                resultadoD = dividir(num1, num2);
                resultadoM = multiplicar(num1, num2);
                resultadoF1 = factorial(num1);
                resultadoF2 = factorial(num2);
                printf("\nLos numeros han sido calculados exitosamente.\n");
            }
            break;
        case 4:
            if(flagNum1 == 0 || flagNum2 == 0)
            {
                printf("\nAl menos uno de los dos numeros no fue ingresado. Ingrese los 2 numeros para calcular.\n");
            }
            else
            {


                printf("\n%f + %f = %f",num1,num2, resultadoS);
                printf("\n%f - %f = %f",num1,num2, resultadoR);
                if(num2 == 0)
                {
                    printf("\nNo es posible dividir por cero.");
                }
                else
                {
                    printf("\n%f / %f = %f",num1,num2, resultadoD);
                }
                printf("\n%f * %f = %f",num1,num2, resultadoM);
                printf("\nEl factorial de %f es %f", num1, resultadoF1);
                printf("\nEl factorial de %f es %f", num2, resultadoF2);
            }
            break;

        case 5:

            flagWhile = 1;
            break;

        default:
            printf("\nEste numero no ejecuta ninguna operacion.\n");
            break;
        }
    }
}
