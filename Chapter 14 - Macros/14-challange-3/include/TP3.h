#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 5


typedef struct Element {
  char *data;
  struct Element* next;
} Element;

typedef struct List {
  struct Element * head;
  struct Element * tail;
} List;



void initialize (List *list);
int nouv_Element(char* text, Element* e);
int insertElement(char* text, List* l);
void insert_empty_list(List *list, char *str);
void insert_begining_list(List *list, char *str);
void insert_end_list(List *list, char *str);
int insert_after_position(List *list, char *str, int p);
void merge(unsigned long long int *Arr, int start, int mid, int end);
void mergeSort(unsigned long long int *Arr, int start, int end);
void sum(List *list);
Element* find_after_position(List *list, int p);
int my_remove(List *list, int p);
int compare(char *str1, char *str2);
int sort (List *list);
void merge(unsigned long long int *Arr, int start, int mid, int end);
void MergeSort(Element** h);
Element* SortedMerge(Element* fst, Element* snd);
void Splitter(Element* src, Element** fstList, Element** sndList);
void display(List *list);
void destruct (List *list);











