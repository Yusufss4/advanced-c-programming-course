#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void print_menu(void)
{
  printf("Enter your choice:\n"
         "0 to insert an element into the list in the position given.\n"
         "1 to insert an element after the given node. \n"
         "2 to insert an element at the end of the list.\n"
         "3 to insert an element at the beginning of the list.\n"
         "4 to delete an element from the list in the position given.\n"
         "5 to update the value of an element.\n"
         "6 to search a node.\n"
         "7 to print the list.\n"
         "8 to test the linked list.\n"
         "9 to end.\n");
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
      printf("Enter the node data: ");
      scanf("%d", &node_data);
      printf("Enter the node position: ");
      scanf("%d", &node_position);
      insert_node_at_position(&head, create_new_node(node_data), node_position);
      print_node_list(head);
      break;
    }
    case 1:
    {
      printf("Enter the node data: ");
      scanf("%d", &node_data);
      insert_after_node(head, create_new_node(node_data));
      print_node_list(head);
      break;
    }
    case 2:
    {
      printf("Enter the node data: ");
      scanf("%d", &node_data);
      insert_node_at_end(&head, create_new_node(node_data));
      print_node_list(head);
      break;
    }
    case 3:
    {
      printf("Enter the node data: ");
      scanf("%d", &node_data);
      insert_node_at_head(&head, create_new_node(node_data));
      print_node_list(head);
      break;
    }
    case 4:
    {
      printf("Enter the node position: ");
      scanf("%d", &node_position);
      delete_node_at_position(&head, node_position);
      print_node_list(head);
      break;
    }
    case 5:
    {
      printf("Enter the node data: ");
      scanf("%d", &node_data);
      printf("Enter the node position: ");
      scanf("%d", &node_position);
      update_node_value(&head, create_new_node(node_data), node_position);
      print_node_list(head);
      break;
    }
    case 6:
    {
      printf("Enter the node data to search: ");
      scanf("%d", &node_data);
      node_t *node_that_returns = NULL;
      search_node(head, &node_that_returns, node_data);
      printf("Node returned: ");
      print_node(node_that_returns);
      print_node_list(head);
      break;
    }
    case 7:
    {
      print_node_list(head);
      break;
    }
    case 8:
    {
      printf("-- Testing --\n\n");
      printf("create_new_node\n");
      printf("Creating four nodes...\n");
      node_t *node1 = create_new_node(10);
      print_node(node1);
      node_t *node2 = create_new_node(20);
      print_node(node2);
      node_t *node3 = create_new_node(30);
      print_node(node3);
      node_t *node4 = create_new_node(40);
      print_node(node4);

      printf("insert_node_at_position\n");
      node_position = 0;
      printf("Inserting node %p to the head %p at the position of %d...\n",
             node1, head, node_position);
      insert_node_at_position(&head, node1, node_position);
      print_node_list(head);
      node_position = 0;
      printf("Inserting node %p to the head %p at the position of %d...\n",
             node3, head, node_position);
      insert_node_at_position(&head, node3, node_position);
      print_node_list(head);
      node_position = 1;
      printf("Inserting node %p to the head %p at the position of %d...\n",
             node4, head, node_position);
      insert_node_at_position(&head, node4, node_position);
      print_node_list(head);

      printf("insert_node_at_end\n");
      node_t *node5 = create_new_node(50);
      printf("Inserting node %p to the head %p at the end of the list...\n",
             node5, head);
      insert_node_at_end(&head, node5);
      print_node_list(head);
      node_t *node6 = create_new_node(60);
      printf("Inserting node %p to the head %p at the end of the list...\n",
             node6, head);
      insert_node_at_end(&head, node6);
      print_node_list(head);

      printf("insert_after_node\n");
      node_t *node7 = create_new_node(70);
      printf("Inserting node %p to the head %p after the node %p...\n",
             node1, head, node7);
      insert_after_node(node1, node7);

      printf("insert_node_at_head\n");
      node_t *node8 = create_new_node(80);
      printf("Inserting node %p to the head %p as head node\n",
             node8, head);
      insert_node_at_head(&head, node8);
      print_node_list(head);

      printf("delete_node_at_position\n");
      node_position = 3;
      printf("Deleting node in the list head %p at the position %d\n", head, node_position);
      delete_node_at_position(&head, node_position);
      print_node_list(head);

      printf("delete_node_at_position\n");
      node_position = 0;
      printf("Deleting node in the list head %p at the position %d\n", head, node_position);
      delete_node_at_position(&head, node_position);
      print_node_list(head);

      printf("update_node_value\n");
      node_position = 2;
      node_t *node9 = create_new_node(90);
      printf("Changing node in the list head %p at the position %d with the node %p\n", head, node_position, node9);
      update_node_value(&head, node9, node_position);
      print_node_list(head);

      printf("search_node\n");
      node_data = 40;
      node_t *return_node = NULL;
      printf("Searching node with data %d in the list head %p\n", node_data, head);
      node_position = search_node(head, &return_node, node_data);
      printf("Node Returned at the position %d. Information:\n", node_position);
      print_node(return_node);
      print_node_list(head);

      break;
    }
    case 9:
    {
      exit(EXIT_SUCCESS);
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