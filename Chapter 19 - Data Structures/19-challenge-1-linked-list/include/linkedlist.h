/**
 * @file linkedlist.h
 * @author Yusuf Savas
 * @brief Integer LinkedList Library
 * @version 0.1
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node
{
    int value;
    struct node *next;
} node_t;

node_t *create_new_node(int value);
int insert_node_at_position(node_t **head, node_t *node_to_insert, int node_position);
int insert_after_node(node_t *node_to_insert_after, node_t *new_node);
int insert_node_at_end(node_t **head, node_t *node_to_insert);
int insert_node_at_head(node_t **head, node_t *node_to_insert);
int delete_node_at_position(node_t **head, node_t *node_to_insert, unsigned int node_position);
int update_node_value(node_t **head, node_t *node_to_insert, unsigned int node_position);
int search_node(node_t *head, node_t **return_node, unsigned int node_data);
void print_node_list(node_t *current_ptr);

#endif /* LINKEDLIST_H */