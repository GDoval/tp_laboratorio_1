/**
/brief La funcion devuelve un float
/param Recibe una cadena de caracteres, que es el texto que se imprimirá por pantalla al momento de pedir que se ingrese el dato
/return Devuelve el dato ingresado por el usuario
**/

float IngresoFloat(char texto[]);



/**
/brief Suma dos numeros
/param recibe un dato de tipo float
/param recibe un dato de tipo float
/return devuelve un float con el resultado de la suma de los parametros ingresados.
**/
float Suma(float n1, float n2);

/**
/brief Resta dos numeros
/param Recibe un dato de tipo flotante
/param Recibe un dato de tipo flotante
/return Devuelve un float con el resultado de la resta de los parametros ingresados.
**/


float Resta (float n1, float n2);



/**
/brief Multiplica dos datos de tipo float
/param Recibe un dato de tipo float
/param Recibe un dato de tipo float
/return Devuelve un float con el resultado de la multiplicacion de los parametros ingresados
**/


float Multi(float n1, float n2);


/**
/brief Divide los parametros que recibe, en el orden en que fueron ingresados
/param Recibe un dato de tipo float
/param Recibe un dato de tipo float
/return Devuelve un float con el resultado de la division de los parametros ingresados.
**/


float Divi(float n1, float n2);


/**
/brief Devuelve el char 's' si el parametro ingresado no es un cero, o un char 'n' si, efectivamente, es cero.
/param Recibe un dato de tipo float
/return Devuelve un char 's' ó  'n'
**/


char NoEsCero(float numero);


/**
/brief Calcula el factorial del numero ingresado a través de una estructura repetitiva
/param Recibe un dato de tipo int
/return Devuelve un dato de tipo long long int
**/


long long int Factorial (int num);



/**
/brief Devuelve el char 's' si el numero ingresado como parametro es mayor a cero, o un char 'n' si es menor a cero.
/param Recibe un dato de tipo int
/return Devuelve un char 's' ó 'n'
**/

char MayorCero (int numero);



/**
/brief La funcion evalua cuál de las 6 posibles combinaciones de true or false se cumple a partir de los datos pasados como parametros.
/param Recibe un dato de tipo float
/param Recibe un dato de tipo float
/return Devuelve un int con valor 1, 2, 3, 4, 5 ó 6.
**/



int Posibilidades(float numFac, float numDiv);







/**
/brief La funcion evalua si es posible realizar el factorial del numero pasado como parametro
/param Recibe un dato de tipo float
/return Devuelve un int con valor 1, 2 ó 3.
**/


int validarFacto(float numero);
