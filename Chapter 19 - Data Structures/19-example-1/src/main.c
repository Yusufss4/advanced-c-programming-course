#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
typedef struct node
{
  char data;
  struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

void insert(ListNodePtr *head, char value);
void insert_at_end(ListNodePtr *haed, char value);
void insert_at_beginning(ListNodePtr *head, char value);
char delete_node(ListNodePtr *head, char value);
void delete_at_beginning(ListNodePtr *head);
void print_list(ListNodePtr currentPtr);
int is_list_empty(ListNodePtr head);

void print_menu(void)
{
  printf("Enter your choice:\n"
         " 1 to insert an element into the list in alphabetical order.\n"
         " 2 to insert an element at the end of the list. \n"
         " 3 to insert an element at the beginning of the list.\n"
         " 4 to delete an element from the list.\n"
         " 5 to delete an element from the beginning of the list.\n"
         " 6 to end.\n");
}

int main(void)
{
  ListNodePtr head = NULL; // there are no nodes at first.
  int choice = 0;          // user's choice.
  char item = '\0';        // char entered by the user.

  print_menu();
  printf(":: ");
  scanf("%d", &choice);

  while (choice != 6)
  {
    switch (choice)
    {
    case 1:
      printf("Enter a character: ");
      scanf("\n%c", &item);
      insert(&head, item);
      print_list(head);
      break;

    case 2:
      printf("Enter a character: ");
      scanf("\n%c", &item);
      insert_at_end(&head, item);
      print_list(head);
      break;

    case 3:
      printf("Enter a character: ");
      scanf("\n%c", &item);
      insert_at_beginning(&head, item);
      print_list(head);
      break;

    case 4: // delete an element
      if (!is_list_empty(head))
      {
        printf("Enter character to be deleted: ");
        scanf("\n%c", &item);

        if (delete_node(&head, item))
        {
          printf("%c deleted.\n", item);
          print_list(head);
        }
        else
        {
          printf("%c not found.\n\n", item);
        }
      }
      else
      {
        printf("List is empty.\n\n");
      }
    case 5: // delete an element at beginning.
      if (!is_list_empty(head))
      {
        delete_at_beginning(&head);
        printf("%c deleted.\n", item);
        print_list(head);
      }
      else
      {
        printf("List is empty.\n\n");
      }

    default:
      printf("Invalid choice.\n\n");
      print_menu();
      break;
    }
    printf("? ");
    scanf("%d", &choice);
  }

  printf("End of run.");
  return EXIT_SUCCESS;
}

void insert_at_beginning(ListNodePtr *head, char value)
{
  ListNodePtr new_node = malloc(sizeof(node_t));
  new_node->data = value;
  new_node->nextPtr = *head;
  *head = new_node;
}

void insert_at_end(ListNodePtr *head, char value)
{
  ListNodePtr current = *head;

  if (current != NULL)
  { // traversing the end of the list.
    while (current->nextPtr != NULL)
    {
      current = current->nextPtr;
    }

    current->nextPtr = malloc(sizeof(node_t));
    current->nextPtr->data = value;
    current->nextPtr->nextPtr = NULL;
  }
  else
  {
    current = malloc(sizeof(node_t));
    current->data = value;
    current->nextPtr = NULL;
    *head = current;
  }
}

void insert(ListNodePtr *head, char value)
{
  ListNodePtr newPtr;      /* Pointer to new node. */
  ListNodePtr previousPtr; /* Pointer to previous node in list */
  ListNodePtr currentPtr;  /* Pointer to current node in list */

  newPtr = malloc(sizeof(node_t)); // Create node

  if (newPtr != NULL)
  {
    newPtr->data = value;
    newPtr->nextPtr = NULL;

    previousPtr = NULL;
    currentPtr = *head;

    // loop to find the correct location in the list.
    while (currentPtr != NULL && value > currentPtr->data)
    {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    // insert new node at the beginning of the list.
    if (previousPtr == NULL)
    {
      newPtr->nextPtr = *head;
      *head = newPtr;
    }
    // insert new node between previousPtr and currentPtr
    else
    {
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }
  }
  else
  {
    printf("%c not inserted. No memory avaliable.\n", value);
  }
}

void delete_at_beginning(ListNodePtr *head)
{
  ListNodePtr tempPtr = NULL; // temporary node pointer.

  // check if the list is empty.
  if (head == NULL)
  {
    return;
  }
  else
  {
    tempPtr = *head;          // hold the node being removed.
    *head = (*head)->nextPtr; // make the head next node.
    free(tempPtr);            // free the malloc.
  }
}

char delete_node(ListNodePtr *head, char value)
{
  ListNodePtr previousPtr; /* Pointer to previous node in list */
  ListNodePtr currentPtr;  /* Pointer to current node in list */
  ListNodePtr tempPtr;     /* Temporary node pointer. */

  // delete first node.
  if (value == (*head)->data)
  {
    tempPtr = *head;          // hold the node being removed.
    *head = (*head)->nextPtr; // make the head next node.
    free(tempPtr);            // free the malloc.
    return value;
  }
  else
  {
    previousPtr = *head;
    currentPtr = (*head)->nextPtr;

    // find the correct location in the list.
    while (currentPtr != NULL && currentPtr->data != value)
    {
      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    // delete node at currentPtr
    if (currentPtr != NULL)
    {
      tempPtr = currentPtr;
      previousPtr->nextPtr = currentPtr->nextPtr;
      free(tempPtr);
      return value;
    }
  }
  return '\0';
}

void print_list(ListNodePtr currentPtr)
{
  if (currentPtr == NULL)
  {
    printf("List is empty.\n\n");
  }
  else
  {
    printf("The list is: \n");

    // while not the end of the list.
    while (currentPtr != NULL)
    {
      printf("%c --> ", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }
    printf("NULL\n\n");
  }
}

int is_list_empty(ListNodePtr head)
{
  return head == NULL;
}
