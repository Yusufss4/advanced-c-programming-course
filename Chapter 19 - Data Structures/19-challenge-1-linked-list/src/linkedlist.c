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

void print_node(node_t *node)
{
    if (node != NULL)
    {
        printf("Address of Node: %p\n", node);
        printf("Node Value: %d\n", node->value);
        if (node->next != NULL)
        {
            printf("Addres that the Node holds: %p\n", node->next);
        }
        else
        {
            printf("Addres that the Node holds: NULL\n");
        }
    }
    else
    {
        printf("Address of Node: NULL\n");
    }
}

int insert_node_at_position(node_t **head, node_t *node_to_insert, int node_position)
{
    int retval = ERROR_LINKED_LIST;
    node_t *new_ptr;      /* Pointer to new node. */
    node_t *previous_ptr; /* Pointer to previous node in list */
    node_t *current_ptr;  /* Pointer to current node in list */
    int tmp_node_position = 0;

    if (node_to_insert != NULL)
    {
        node_to_insert->next = NULL;
        previous_ptr = NULL;
        current_ptr = *head;

        // loop to find the correct location in the list.
        while ((current_ptr != NULL) && (tmp_node_position != node_position))
        {
            previous_ptr = current_ptr;
            current_ptr = current_ptr->next;
            tmp_node_position++;
        }

        // insert new node at the beginning of the list.
        if (previous_ptr == NULL)
        {
            node_to_insert->next = *head;
            *head = node_to_insert; // we need keep track of the head.
        }
        // insert new node between previous_ptr and current_ptr
        else
        {
            previous_ptr->next = node_to_insert;
            node_to_insert->next = current_ptr;
        }
    }
    else
    {
        printf("Failure while inserting the new node.\n");
        return ERROR_LINKED_LIST;
    }
    return retval;
}

int insert_after_node(node_t *node_to_insert_after, node_t *new_node)
{
    int retval = ERROR_LINKED_LIST;
    if (node_to_insert_after != NULL && new_node != new_node)
    {
        new_node->next = node_to_insert_after->next;
        node_to_insert_after->next = new_node;
        retval = SUCCESS_LINKED_LIST;
    }
    return retval;
}

int insert_node_at_end(node_t **head, node_t *node_to_insert)
{
    int retval = ERROR_LINKED_LIST;
    node_t *current_ptr; /* Pointer to current node in list */

    if (node_to_insert != NULL)
    {

        node_to_insert->next = NULL;
        current_ptr = *head;
        if (*head != NULL)
        {

            // loop to find the correct location in the list.
            while ((current_ptr->next != NULL))
            {
                current_ptr = current_ptr->next;
            }
            current_ptr->next = node_to_insert;
            return SUCCESS_LINKED_LIST;
        }
        // else if the head is NULL means list is empty.
        else
        {
            *head = node_to_insert;
            return SUCCESS_LINKED_LIST;
        }
    }
    else
    {
        printf("Failure while inserting the new node.\n");
        return ERROR_LINKED_LIST;
    }
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
    return retval;
}
int delete_node_at_position(node_t **head, unsigned int node_position)
{
    int retval = ERROR_LINKED_LIST;
    node_t *previous_ptr; /* Pointer to previous node in list */
    node_t *current_ptr;  /* Pointer to current node in list */
    node_t *temp_ptr;     /* Temporary node pointer. */
    int tmp_node_position = 0;

    // delete first node.
    if (node_position == 0)
    {
        temp_ptr = *head;      // hold the node being removed.
        *head = (*head)->next; // make the head next node.
        free(temp_ptr);        // free the malloc.
        return SUCCESS_LINKED_LIST;
    }
    else
    {
        previous_ptr = *head;
        current_ptr = (*head)->next;

        // find the correct location in the list.
        while (current_ptr != NULL && (tmp_node_position != (node_position - 1)))
        {
            tmp_node_position++;
            previous_ptr = current_ptr;
            current_ptr = current_ptr->next;
        }

        // delete node at current_ptr
        if (current_ptr != NULL)
        {
            temp_ptr = current_ptr;
            previous_ptr->next = current_ptr->next;
            free(temp_ptr);
            return SUCCESS_LINKED_LIST;
        }
    }
    return retval;
}
int update_node_value(node_t **head, node_t *node_to_insert, unsigned int node_position)
{
    int retval = ERROR_LINKED_LIST;
    retval = delete_node_at_position(head, node_position);
    retval = insert_node_at_position(head, node_to_insert, node_position);
    return retval;
}
int search_node(node_t *head, node_t **return_node, unsigned int node_data)
{
    int retval = ERROR_LINKED_LIST;
    node_t *tmp = head;
    *return_node = NULL;
    while (tmp != NULL)
    {
        if (tmp->value == node_data)
        {
            *return_node = tmp;
            return 0; // position.
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return retval;
}
void print_node_list(node_t *current_ptr)
{
    if (current_ptr == NULL)
    {
        printf("List is empty.\n\n");
    }
    else
    {
        printf("The list is: \n");

        // while not the end of the list.
        while (current_ptr != NULL)
        {
            printf("%d -> ", current_ptr->value);
            current_ptr = current_ptr->next;
        }
        printf("NULL\n\n");
    }
    return;
}