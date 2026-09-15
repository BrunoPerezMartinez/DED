#include <stdio.h>

void decode(char *secreto)
{
	char c = *secreto;
	
	while (*secreto != '\0')
	{
		if ((c % 2) == 0)
		{
			*secreto -= 2;
		}
		else
		{
			*secreto += 1;
		}
		secreto++;
	}
}

void incrementarDiagonal(int **matriz, int tamano)
{
    int contador = tamano - 1;
    int *iPtr;

    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            if (contador == i)
            {
                **iPtr += 1;
            }

            *matriz++;
        }
        contador--;
        *matriz++;
    }
}

void impresionVoid(void * vPtr, int tipo)
{
    switch(tipo)
    {

        case 0:
            printf("%d", (int *)vPtr);
            break;

        case 1:
            printf("%c", (char *)vPtr);
            break;

        case 2:
            printf("%f", (float *)vPtr);
            break;

        case 3:
            printf("%p", vPtr);
            break;
    }
}

int main()
{

    //Ejercicio 3
    char secreto[10] = "Ewmehqmc";

    printf("Palabra secreta: %s\n", secreto);

    char *secretoPtr = secreto;

    decode(secretoPtr);

    printf("Palabra decodificada: %s", secreto);

    //Ejercicio 4


    //Ejercicio 5
    Typedef int (*fPtr1)(char, float);
    Typedef char *(*fPtr2)(void);
    Typedef float * (*fPtr3)(void *);
    Typedef void (*fPtr5)(void);
    Typedef char (*fPtr6) (void);
}