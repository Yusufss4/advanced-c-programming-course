#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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

  node_t *head = NULL;

  printf("----------------------------------\n");
  printf("-------Lınked List Challenge 1----\n");
  printf("----------------------------------\n");
  int option = 0;
  int node_position = 0;
  int node_data = 0;
  while (1)
  {
    print_menu();
    scanf("%d", &option);
    switch (option)
    {
    case 0:
    {
      insert_node_at_position(&head, create_new_node(0), node_position);
      break;
    }
    case 1:
    {
      insert_after_node(head, create_new_node(0));
      break;
    }
    case 2:
    {
      insert_node_at_end(&head, create_new_node(0));
      break;
    }
    case 3:
    {
      scanf("%d", &node_data);
      insert_node_at_head(&head, create_new_node(node_data));
      break;
    }
    case 4:
    {
      delete_node_at_position(&head, create_new_node(0), node_position);
      break;
    }
    case 5:
    {
      update_node_value(&head, create_new_node(0), node_position);
      break;
    }
    case 6:
    {
      node_t *node_that_returns = NULL;
      search_node(head, &node_that_returns, node_data);
      break;
    }
    case 7:
    {
      node_t *node_that_returns = NULL;
      search_node(head, &node_that_returns, node_data);
      break;
    }
    case 8:
    {
      print_node_list(head);
      break;
    }
    default:
    {
      printf("Wrong value. Please enter again.\n");
      break;
    }
    }
  }
  return EXIT_SUCCESS;
}