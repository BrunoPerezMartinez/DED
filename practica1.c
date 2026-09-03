#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex01()
{
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    int *iptr = x;

    for (int i = 0; i < 10; i++)
    {
        printf("%d address: %p\n", *(iptr + i), iptr + i);
    }
}

int ex02(char *array)
{
    int length = 0;
    while (*array != '\0')
    {
        (length)++;
        array++;
    }
    return length;
}

void ex03(char *array)
{
    while (*array != '\0')
    {
        if (*array >= 'A' && *array <= 'Z')
        {
            *array = *array + 32;
        }
        array++;
    }
}

void ex04(char *array)
{
    int esBinario = 0;
    while (*array != '\0')
    {
        if (*array != '0' && *array != '1')
        {
            esBinario = 1;
            continue;
        }
        else
        {
            esBinario = 0;
            break;
        }
        array++;
    }

    if (esBinario == 0)
    {
        printf("La cadena no es binaria\n");
    }
    else
    {
        printf("La cadena es binaria\n");
    }
}

int main()
{
    char string[44] = "O Pato vihna cantando alegremente QUEM QUEM";

    ex01();
    printf("%d\n", ex02(string));
    ex03(string);

    for (int i = 0; i < 44; i++)
    {
        printf("%c", string[i]);
    };

    char cadena[100];
    printf("\nIngrese una cadena de texto: ");
    scanf("%s", cadena);

    ex04(cadena);

    return 0;
}