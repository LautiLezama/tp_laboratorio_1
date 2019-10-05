#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define ELEMENTS 1000


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief Funcion encargada de iniciar el campo "isEmpty" de los empleados en TRUE, afirmando que los slots estan vacios.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return int Retorna 0 en caso de que se haya inicializado correctamente, de lo contrario, al retornar 1 imprime un mensaje de error.
 *
 */
int initEmployees(Employee*, int);
/** \brief Funcion encargada de cargar los datos ya solicitados a una posicion del array de empleados.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \param int Numero de ID.
 * \param char[] Nombre del empleado.
 * \param char[] Apellido del empleado.
 * \param float Salario del empleado.
 * \param int Sector del empleado.
 * \return int Retorna 0 en caso de que los datos se hayan cargado correctamente, de lo contrario, al retornar 1 imprime un mensaje de error.
 *
 */
int addEmployee(Employee*, int, int, char[], char[],float , int);
/** \brief Funcion encargada de encontrar un empleado segun el numero de ID ingresado por el usuario.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return int Retorna 0 en caso de que se haya encontrado al empleado correctamente, de lo contrario, al retornar 1 imprime un mensaje de error.
 *
 */
int findEmployeeById(Employee*, int);
/** \brief Funcion encargada de borrar un empleado, el empleado a borrarse lo ingresara el usuario segun el ID.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return int Retorna 0 en caso de que se haya borrado al empleado correctamente, -1 en caso de que haya un error o 1 en caso de que el usuario cancelara la acción.
 *
 */
int removeEmployee(Employee*, int);
/** \brief Funcion encargada de ordenar a los empleados segun sector y apellido.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return int Retorna 0 en caso de que se hayan ordenado correctamente, -1 en caso de que haya un error.
 *
 */
int sortEmployees(Employee*, int, int);
/** \brief Funcion encargada de imprimir la lista de empleados ordenados de forma encolumnada.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return int Retorna 0 en caso de que se hayan imprimido correctamente, -1 en caso de que haya un error.
 *
 */
int printEmployees(Employee*, int);
/** \brief Funcion encargada de buscar el primer lugar vacio del Puntero de Array de empleados.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return int Retorna 0 en caso de que se haya conseguido el lugar vacio, -1 en caso de que haya un error o no se encontrara lugar vacio.
 *
 */
int searchIsEmpty(Employee*, int);
/** \brief Funcion encargada de modificar un empleado segun la ID ingresada por el usuario.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return int Retorna 0 en caso de que se haya modificado al empleado exitosamente, -1 en caso de que haya un error y 1 en caso de que el usuario no elija una opcion valida.
 *
 */
int modifyEmployee(Employee*, int);
/** \brief Funcion encargada de comprobar que haya al menos un empleado cargado.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return int Retorna 0 en caso de que haya un empleado como minimo cargado, -1 en caso de que no haya ningun empleado cargado.
 *
 */
int flagEmployee(Employee*, int);
/** \brief Funcion que ejecuta el menu principal de acciones.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \param int Id del empleado.
 * \param char[] Nombre del empleado.
 * \param char[] Apellido del empleado.
 * \param float Salario del empleado.
 * \param int Sector del empleado.
 * \return void
 *
 */
void menuEmployees(Employee*, int, int, char[], char[],float , int);
/** \brief Funcion para ingresar enteros.
 *
 * \param int Variable donde guardar el entero.
 * \return int El entero ya ingresado.
 *
 */
int enterInt(int);
/** \brief Funcion para ingresar flotantes.
 *
 * \param float Variable donde guardar el flotante.
 * \return float El flotante ya ingresado.
 *
 */
float enterFloat(float);
/** \brief Funcion para ingresar un String.
 *
 * \param char* Puntero donde guardar el String.
 * \return char* El String ya ingresado.
 *
 */
char* enterString(char*);
/** \brief Funcion para sacar el promedio de salarios.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \return float Promedio de salarios.
 *
 */
float averageSalary(Employee*, int);
/** \brief Funcion encargada de obtener la cantidad de empleados que superen el promedio de salarios.
 *
 * \param Employee* Puntero de Array de empleados.
 * \param int Cantidad maxima del array de empleados.
 * \param int Promedio de salarios.
 * \return int Cantidad de empleados que superan el promedio.
 *
 */
int employeesWithMoreSalary(Employee*, int, int);

/** \brief Funcion encargada de, en caso de que la primera letra sea minuscula, pasarla a mayuscula.
 *
 * \param char[] String ingresado(Nombre o apellido).
 * \return void
 *
 */
void firstLetterMayus(char[]);
/** \brief Funcion encargada de validar solo la presencia de numeros en el string.
 *
 * \param [] char  String ingresado(Nombre o apellido).
 * \return int
 *
 */
int onlyLetters(char []);
/** \brief Funcion encargada de pasar todas las letras que no sean la primera a minuscula.
 *
 * \param [] char String ingresado(Nombre o apellido).
 * \return void
 *
 */
void toLowerCase(char []);









