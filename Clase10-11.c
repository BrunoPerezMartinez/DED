#include <stdio.h>
#include <stdlib.h>

// ESTE ARCHIVO CONTIENE LA TEORIA DE ARBOLES BINARIOS
// necesaria para construir el tda_set (SET  o conjunto en espaniol)

typedef struct node
{
  int value;
  struct node * left;
  struct node * right;
} node;

typedef int boolean;
#define TRUE 1
#define FALSE 0

void print_inorder(node * n);
boolean contains_iter(node * n, int value);
boolean contains_recur(node * n, int value);

node * create_node(int value);
boolean add_iter(int value);
boolean add_recu(node *node, int value);

/* En todos estos ejemplos, el aputandor root contiene la raiz
de nuestro arbol binario, es una apuntador global de la misma
manera de que "header" era un apuntador global en nuestras listas
o stack_top era un apuntador global de nuenstro stack.

Despues de entender la logica, lo convertiremos en un TDA */

node * root = NULL;

/*             root
                 25
              /      \
          20           36
         /  \         /   \
       10    22     30     40
                   /
                  28
*/

/* Ejemplo 1, con un arbol que ya existe para comprobar como podemos
   recorrerlo */

void example2()
{
  int numbers[10] = {5, 4, 6, 5, 8, 10, 2, 1, 10, 7};

  //agregar todos los numeros de arreglo al arbol binario, NO PUEDEN EXISTIR
  //REPETIDOS en el Arbol, por eso es un SET (conjunto)
  root = create_node(0);
  
  for (int x = 0; x<10; x++)
  {
    printf("Adding %d to BST(Set)\n", numbers[x]);
    add_iter(numbers[x]);
  }
  print_inorder(root);
}

/* Aqui solo tienen que aprender a 
 imprimir y recorrer el arbol existente.
 root ya apunta al arbol */
void example1()
{
 // ====  Creacion estatica del arbol 
  node n25;
  n25.value = 25;
  node n20, n36;
  n20.value = 20; n36.value = 36;
  n25.left = &n20; n25.right = &n36;
  node n10, n22, n30, n40;
  n10.value = 10;  n22.value=22; n30.value=30; n40.value=40;
  n20.left = &n10; n20.right = &n22; n36.left=&n30; n36.right=&n40;
  n10.left=NULL; n10.right=NULL;
  n22.left=NULL; n22.right=NULL;
  n30.right=NULL;
  n40.left=NULL; n40.right=NULL;
  node n28;
  n28.value = 28; n28.left = NULL; n28.right = NULL;
  n30.left=&n28;   
  root = &n25;
//====   Fin de creacion estatica del arbol.

  //print in order (recursivo)
  printf("PRINTING IN ORDER\n");
  print_inorder(root);
  
  //print pre order (recursivo)
  
  //print post order (recursivo)

  //contains iterativo (iterativo)
  /**/
  printf("\n28 %s",contains_iter(root, 28)?"\tTRUE":"\tFALSE");
  printf("\n25 %s",contains_iter(root, 25)?"\tTRUE":"\tFALSE");
  printf("\n42 %s",contains_iter(root, 42)?"\tTRUE":"\tFALSE");

  printf("\n");

  //contains (recursivo) 
  printf("\n28 %s",contains_recur(root, 28)?"\tTRUE":"\tFALSE");
  printf("\n25 %s",contains_recur(root, 25)?"\tTRUE":"\tFALSE");
  printf("\n42 %s",contains_recur(root, 42)?"\tTRUE":"\tFALSE");

  //Si te da curiosidad, si si puedes imprimir inorder sin recursion:
  //https://www.educative.io/answers/how-to-perform-an-iterative-inorder-traversal-of-a-binary-tree
  //pero necesitas un stack!
  
  
  return;
}

node * create_node(int num)
{
  node * node = malloc (sizeof(node));
  node->value = num;
  node->left = NULL;
  node->right = NULL;
  return node;
}

//Ojo esta implementacion solo funciona para raices NO NULL, el set
//tiene que tener un elemento.
boolean add_recu(node *node, int num)
{
  
}

boolean add_iter(int num)
{
 
}

boolean add_iter2(node * n, int value)
{
  if(contains_recur(n, value) == TRUE)
  {
    return FALSE;
  }
  
  node * nuevo = create_node(value);

  if(n == NULL)
  {
    root = nuevo;
  }
  else
  {
    node * temp = root;
    while(temp != NULL)
    {
      if(value < temp->value)
      {
        if(temp->left == NULL)
        {
          temp->left = nuevo;
          break;
        }
        else
        {
          temp = temp->left;
        }
      }
      else
      {
        if(temp->right == NULL)
        {
          temp->right = nuevo;
          break;
        }
        else
        {
          temp = temp->right;
        }
      }
      value++;
    }
  }
}

void print_inorder(node *n)
{
  if (n == NULL)
  {
    return;
  }

  print_inorder(n->left);

  printf("%d ", n->value);

  print_inorder(n->right);
}

void print_postorder(node *n)
{
  if (n == NULL)
  {
    return;
  }

  print_postorder(n->left);

  print_postorder(n->right);

  printf("%d ", n->value);
}

void print_preorder(node *n)
{
  if (n == NULL)
  {
    return;
  }

  printf("%d ", n->value);

  print_preorder(n->left);

  print_preorder(n->right);
}

boolean contains_recur(node * n, int value)
{
  node * temp = n;

  if (temp == NULL)
  {
    return FALSE;
  }

  if (temp->value == value)
  {
    return TRUE;
  }
  else if (value < temp->value)
  {
    return contains_recur(temp->left, value);
  }
  else
  {
    return contains_recur(temp->right, value);
  }

}

boolean contains_iter(node * n, int value)
{
  node * temp = n;

  while(temp->value != value)
  {
    if (value < temp->value)
    {
      temp = temp->left;
    }
    else
    {
      temp = temp->right;
    }

    if(temp == NULL)
    {
      return FALSE;
    }
  }
  if (temp->value == value)
  {
    return TRUE;
  }

  return FALSE;
}

boolean contains_iter_noprint(node * n, int value)
{
 
}


int main()
{
  example1();

  printf("\n\n");
  example2(); 
}

