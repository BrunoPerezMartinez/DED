#include <stdio.h>
#define CLEAR printf("\033[0;0H\033[2J");
/* 
  Excercise 1 : swap
  Create a function that "swaps" the contents of two variables.
  It should receive two intengers, return nothing and after it execution
  whatever what inside one variable should be inside the other and viceversa 
  
*/

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* Excercise 2 : blackjack

Create a blackjack function that:
  -receives 2 numbers and a FLAG (char)
  -returns 1 if the sum of the numbers is positive (greater than 0).
  -returns 0 if the sum of the numbers is negative.
  -Stores the sum of the two numbers in number2.
  -If the sum is 21, set the FLAG to = 'W' (winner)

   IN  IN/OUT  OUT
 (num1, num2, flag)

*/

int blackjack(int a, int *b, char *flag)
{
  *b += a;

  if (*b == 21)
  {
    *flag = 'W';
  }
  if (*b > 0)
  {
    return 1;
  }
  
  return 0;
}

int main()
{
  CLEAR
  /* Exercise 1:  swap num1 and num2 value */
  int num1 = 10;
  int num2 = 20;

  swap(&num1, &num2);
  printf("num1 = %d, num2 = %d\n", num1, num2);

  int num3 = 11;
  int num4 = 10;
  char flag = ' ';

  blackjack(num3, &num4, &flag);

  printf("num3 = %d, num4 = %d, flag = %c\n", num3, num4, flag);
  return 0;
}