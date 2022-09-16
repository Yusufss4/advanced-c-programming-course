#include <stdio.h>
#include <stdlib.h>

struct QNode
{
  int key;
  struct QNode *next;
};

struct Queue
{
  struct QNode *front;
  struct QNode *rear; // end of the queue
};

struct QNode *newNode(int value)
{
  struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
  temp->key = value;
  temp->next = NULL;
  return temp;
};

struct Queue *createQueue()
{
  struct Queue *current_queue = (struct Queue *)malloc(sizeof(struct Queue));
  current_queue->front = NULL;
  current_queue->rear = NULL;
  return current_queue;
}

/**
 * @brief Adding an node to the end of the queue.
 *
 * @param current_queue
 * @param value
 */
void enQueue(struct Queue *current_queue, int value)
{
  struct QNode *temp = newNode(value);

  // if the queue is empty, then new node is front and rear both.
  if (current_queue->rear == NULL)
  {
    current_queue->front = temp;
    current_queue->rear = temp;
    return;
  }

  // add the new node at the end of queue and change rear.
  current_queue->rear->next = temp;
  current_queue->rear = temp;
  return;
}

/**
 * @brief Adding an node to the start of the queue.
 *
 * @param current_queue
 * @return struct QNode*
 */
struct QNode *deQueue(struct Queue *current_queue)
{

  // if the queue is empty, return NULL.
  if (current_queue->front == NULL)
  {
    return NULL;
  }

  // store the previous front and move front one node ahead.
  struct QNode *temp = current_queue->front;
  current_queue->front = current_queue->front->next;

  // when a node is removed from the queue, the queue becomes empty.
  if (current_queue->front == NULL)
  {
    current_queue->rear = NULL;
  }

  return temp;
}

void printQueue(struct Queue *current_queue) {
  
  if (current_queue->front == NULL)
  {
    printf("Queue is empty.\n");
    return;
  }

  printf("\n------------------\n");
  // store the previous front and move front one node ahead.
  struct QNode *temp = current_queue->front;
  while(temp != NULL) {
    printf("%d ", temp->key);
    temp = temp->next;
  }
  printf("<< ");
  printf("\n------------------\n");

  return;
}

int main()
{
  struct Queue *my_queue = createQueue();
  enQueue(my_queue, 1);
  printQueue(my_queue);
  enQueue(my_queue, 2);
  printQueue(my_queue);
  deQueue(my_queue); 
  printQueue(my_queue);
  deQueue(my_queue);
  printQueue(my_queue);
  enQueue(my_queue, 3);
  printQueue(my_queue);
  enQueue(my_queue, 4);
  printQueue(my_queue);
  enQueue(my_queue, 5);
  printQueue(my_queue);
  struct QNode *removed_node = deQueue(my_queue);
  if (removed_node != NULL)
  {
    printf("Dequeued item is %d\n", removed_node->key);
  }
  printQueue(my_queue);
  
  return 0;
}
