#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 5
#define STACK_EMPTY (-1)
#define STACK_ERROR_EMPTY_STACK (-1)
#define STACK_ERROR_STACK_IS_FULL (-1)
#define STACK_SUCCESS 0

typedef struct
{
  int values[STACK_MAX_SIZE]; // elements are stored in the array.
  int top;                    // number of elements in the stack.
} stack_t;

int push(stack_t *current_stack, int value);
int pop(stack_t *current_stack, int *stack_error);
int display(stack_t *current_stack);

int main()
{
  int choice;
  int option = 1;
  int value = 0;
  int retval = -1;

  stack_t first_stack;
  stack_t *first_stack_p = &first_stack;
  first_stack_p->top = STACK_EMPTY;

  while (option)
  {
    printf("----------------------------------\n");
    printf("    1 -->  PUSH\n");
    printf("    2 -->  POP \n");
    printf("    3 -->  DISPLAY \n");
    printf("    4 -->  EXIT \n");
    printf("----------------------------------\n");

    printf("Enter your choice\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the value: \n");
      scanf("%d", &value);
      if (push(first_stack_p, value) == STACK_ERROR_STACK_IS_FULL)
      {
        printf("Stack is full. Could not add the value %d\n", value);
      }
      break;
    case 2:
      value = pop(first_stack_p, &retval);
      if (retval == STACK_ERROR_EMPTY_STACK)
      {
        printf("Stack is empty.\n");
      }
      else
      {
        printf("Popped: %d\n", value);
      }
      break;
    case 3:
      display(first_stack_p);
      break;
    case 4:
      return EXIT_SUCCESS;
      break;

    default:
      break;
    }

    fflush(stdin);
    printf("Do you want to continue (0/1)?\n");
    scanf("%d", &option);
  }
  printf("Exiting program...\n");
  return EXIT_SUCCESS;
}

int push(stack_t *current_stack, int value)
{
  if (current_stack->top >= STACK_MAX_SIZE - 1)
  {
    return STACK_ERROR_STACK_IS_FULL;
  }

  current_stack->top++;
  current_stack->values[current_stack->top] = value;
  return STACK_SUCCESS;
}

int pop(stack_t *current_stack, int *stack_error)
{
  if (current_stack->top == STACK_EMPTY)
  {
    *stack_error = STACK_ERROR_EMPTY_STACK;
    return -1;
  }
  else
  {
    int result = current_stack->values[current_stack->top];
    current_stack->top--;
    *stack_error = STACK_SUCCESS;
    return result;
  }
}

int display(stack_t *current_stack)
{
  int i = 0;
  if (current_stack->top == STACK_EMPTY)
  {
    printf("Stack is empty.\n");
    return false;
  }
  else
  {
    printf("\nThe status of the stack is \n");
    for (i = current_stack->top; i >= 0; i--)
    {
      printf("%d\n", current_stack->values[i]);
    }
  }
  printf("\n");
}
