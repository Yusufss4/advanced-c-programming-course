#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
typedef struct node
{
  int data;
  struct node *link;
} node_t;

node_t *top;

void push(int data)
{
  node_t *temp = malloc(sizeof(node_t));

  if (temp != NULL)
  {
    temp->data = data;
    temp->link = top;
    top = temp;
  }
}

int is_empty()
{
  return top == NULL;
}

void pop()
{
  node_t *temp;
  if (top != NULL)
  {
    temp = top;
    top = top->link;
    temp->link = NULL;
    free(temp);
  }
}

void display()
{
  printf("Stack Top: %p --> ",top);
  node_t *temp;
  if (top != NULL)
  {
    temp = top;
    while (temp != NULL)
    {
      printf("%d:", temp->data);
      temp = temp->link;
    }
  }
  printf("\n");
}

int main()
{

  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  display();

  pop();
  pop();

  display();

  return EXIT_SUCCESS;
}
