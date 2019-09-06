
#include <stdio.h>


/** \brief Funcion usada para pedir numeros.
 *
 * \param char[] El mensaje, en este caso determinamos en el main que numero sera(ej primer numero).
 * \param float El numero ingresado por el usuario.
 * \return float La funcion retorna un numero para usar en las futuras operaciones.
 *
 */
float pedirNum(char[],float);


/** \brief Funcion para sumar 2 valores.
 *
 * \param float El primer valor.
 * \param float El segundo valor.
 * \return float Devuelve el resultado de la suma.
 *
 */
float sumar(float, float);


/** \brief Funcion para restar 2 valores.
 *
 * \param float El primer valor.
 * \param float El segundo valor.
 * \return float Devuelve el resultado de la resta.
 *
 */
float restar(float, float);


/** \brief Funcion para dividir 2 valores.
 *
 * \param float El primer valor
 * \param float El segundo valor
 * \return float Devuelve el resultado de la division.
 *
 */
float dividir(float, float);


/** \brief Funcion para multiplicar 2 valores.
 *
 * \param float El primer valor
 * \param float El segundo valor
 * \return float Devuelve el resultado de la multiplicacion
 *
 */
float multiplicar(float, float);


/** \brief Funcion para calcular el factorial de un valor.
 *
 * \param float El valor ingresado.
 * \return float Devuelve el factorial del mismo.
 *
 */
float factorial(float);


/** \brief Funcion en la que se usan todas las funciones nombradas anteriormente para calcular el resultado de la suma, resta,
division, multiplicación y factoriales de los valores ingresados y luego mostrarlos en la consola.
 *
 * \param float El primer valor.
 * \param float El segundo valor.
 * \return void Aplica todo dentro de las funciones sin devolver nada al main.
 *
 */
void calcular(float, float);

