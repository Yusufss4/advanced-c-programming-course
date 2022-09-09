/**
 * @file linkedlist.c
 * @author Yusuf Savaş
 * @brief
 * @version 0.1
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t)); // create new memory for new node.
    result->value = value;
    result->next = NULL;
    return result; // return the newly created node.
}

int insert_node_at_position(node_t **head, node_t *node_to_insert, int node_position)
{
    int retval = -1;
    return retval;
}

int insert_after_node(node_t *node_to_insert_after, node_t *new_node)
{
    int retval = -1;
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
    retval = 0;
    return retval;
}

int insert_node_at_end(node_t **head, node_t *node_to_insert)
{
    int retval = -1;
    return retval;
}
int insert_node_at_head(node_t **head, node_t *node_to_insert)
{
    int retval = -1;

    if (NULL != node_to_insert)
    {
        node_to_insert->next = *head;
        *head = node_to_insert;
        return 0;
    }
    else
    {
        printf("Error inserting node at the head.\n");
        return retval;
    }
}
int delete_node_at_position(node_t **head, node_t *node_to_insert, unsigned int node_position)
{
    int retval = -1;
    return retval;
}
int update_node_value(node_t **head, node_t *node_to_insert, unsigned int node_position)
{
    int retval = -1;
    return retval;
}
int search_node(node_t *head, node_t **return_node, unsigned int node_data)
{
    int retval = -1;
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == node_data)
        {
            *return_node = tmp;
            return 0; // position.
        }
        else
        {
            *return_node = NULL;
            return -1;
        }
    }
    return retval;
}
void print_node_list(node_t *current_ptr)
{
    int retval = -1;
}