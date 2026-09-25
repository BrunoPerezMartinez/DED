#include <stdio.h>
#include <stdlib.h>

/* Ejercicios Malloc / Free 

  UTILIZA MEMORIA DINAMICA PARA TODO ESTE EJERCICIO.

  Regla de ORO, por cada malloc, debe de existir un FREE */
int main()
{
  /* 1) crea un entero, con valor = 10 */
  int * num = malloc(sizeof(int));
  *num = 10;

  printf("Valor: %d\n", *num);
  printf("Direccion de memoria: %p\n", num);

  /* 1.1 ... libera ese entero */
  free(num);
  printf("Valor: %d\n", *num);
  printf("Direccion de memoria: %p\n", num);

  /* 2) crea un arreglo de 10 enteros */
  int * arreglo = malloc(10*sizeof(int));

  /* 2.1) rellena ese arreglo con numeros del 1 al 10, imprimero para
    corroborar */
  int *arreglotemp = arreglo;

  for(int i = 0; i < 10; i++)
  {
    *arreglotemp = i+1;
    printf("Arreglo[%d] tiene el valor: %d\n", i, *arreglotemp);
    arreglotemp++;
  }
  
  /* 2.2 ) destruye el arreglo, ya no lo quiero */

  free(arreglo);

  for(int i = 0; i < 10; i++)
  {
    printf("Arreglo[%d] tiene el valor: %d\n", i, *arreglo);
    arreglo++;
  }

  /* 3, crea un arreglo de 20 chars, guarda en el tu nombre (pidelo de teclado) */
  char * nombre = malloc(20);

  printf("Ingresa tu nombre: ");
  scanf("%s", nombre);
  
  /* 3.1 imprimelo */
  printf("Tu nombre es: %s", nombre);
  
  /* 3.2 destruyelo */
  free(nombre);

  /* Y quien va a destruir todos los apuntadores que hemos hecho?
    El mismo programa, porque fueron creados con memoria ESTATICA, su  
    scope de vida (alcance) es solo el metodo main */

  /* ==================================================================== */  
}