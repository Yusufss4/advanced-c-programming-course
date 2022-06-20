#include"TP3.h"


void initialize (List *list)
{
	list->head = NULL; 
	list->tail = NULL; 
}


int nouv_Element(char* text, Element* e){
    e->next = NULL;
    char subbuff[N+1];
    int i;
    for(i = 0; text[i] && i < 5; i++)
        subbuff[i] = text[i];
    
    subbuff[i] = '\0';
    e->data = (char *)malloc(N+1);
    strcpy(e->data, subbuff);
  return i;
}



int insertElement(char* text, List* l){
  Element* ElementaCreer = malloc(sizeof(struct Element));
  int toReturn = nouv_Element(text,ElementaCreer);
  if(!l->head){
    l->head = ElementaCreer;
    l->tail = ElementaCreer;
  }else{
    l->tail->next = ElementaCreer;
    l->tail = l->tail->next;
  }
  return toReturn;
}

void insert_empty_list(List *list, char *str){
  int i = 0;
  while(str[i]){    
    i+=insertElement(str+i, list);    
  }
  Element* ElementNull = malloc(sizeof(struct Element));
  ElementNull->data=NULL;
  list->tail->next=ElementNull;
  list->tail=ElementNull;

}
  

void insert_begining_list(List *list, char *str){
  int i = 0;
  List *temp = (List *) malloc(sizeof(List));
  Element* ElementNull = malloc(sizeof(struct Element));
    ElementNull->data=NULL;

  ElementNull->next = list->head;
  initialize(temp);
  while(str[i]){    
    i+=insertElement(str+i, temp);    
  }
  temp->tail->next = ElementNull;
  list->head=temp->head;
}


void insert_end_list(List *list, char *str)
{
  int i = 0;
  List *temp = (List *) malloc(sizeof(List));
  Element* ElementNull = malloc(sizeof(struct Element));
  ElementNull->data=NULL;
  initialize(temp);
  while(str[i]){    
    i+=insertElement(str+i, temp);    
  }
  list->tail->next = temp->head;
  temp->tail->next =ElementNull;
  temp->tail=ElementNull;
  list->tail = temp->tail;
}


int insert_after_position(List *list, char *str, int p){
    int i = 0;
    
    List *temp = (List *) malloc(sizeof(List));
    Element* ElementNull = malloc(sizeof(struct Element));
    ElementNull->data=NULL;
    initialize(temp);
    while(str[i]){    
        i+=insertElement(str+i, temp);    
    }

    temp->tail->next=ElementNull;
    temp->tail = temp->tail->next;
    if (p==0){
        temp->tail->next = list->head;
        list->head = temp->head;
        return 1;
    }
    Element* current = list->head;
    while (current->next && p>0){
        current = current->next;
        if(current->data==NULL){
            p--;    
        }
    }
    temp->tail->next = current->next;
    current->next = temp->head;
    return 1;

}

Element* find_after_position(List *list, int p){
    Element* current = list->head;
    if (p==0){
        while (current->next && p>-1){
            current = current->next;
            if(current->data==NULL){
                p--;    
            }   
        }
    }
    else{
        while (current->next && p>0){
        current = current->next;
        if(current->data==NULL){
            p--;    
        }
    }
    }
    
    return current; 
}
int my_remove(List *list, int p){
    if (p==0){
        list->head = find_after_position(list,  p)->next;
        return 1;
    }
    else{
        find_after_position(list,  p)->next = find_after_position(list,  p+1)->next;
    }
    
    return 1; 

}

int compare(char *str1, char *str2){
    int nmbre1 = atoi(str1);
    int nmbre2 = atoi(str2);
    if (nmbre1>=nmbre2) return 1;
    return 2;
}







void Splitter(Element* src, Element** fstList, Element** sndList){
    Element* fast;
    Element* slow;
    slow = src;
    fast = src->next;
 
    /* fastis moving 2 nodes to the front, while slow moves only 1 
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* slow is in the middle of the list, so let's split there */
    *fstList = src;
    *sndList = slow->next;
    slow->next = NULL;
}

Element* SortedMerge(Element* fst, Element* snd)
{
    Element* final = NULL;
 

    //Stop cases
    if (!fst)
        return (snd);
    else if (!snd)
        return (fst);
 
    //Let's see who is smaller, put in the base of the list, and let's say the next of the list is the smaller between the others
    if (atoi(fst->data) <= atoi(snd->data)) {
        final = fst;
        final->next = SortedMerge(fst->next, snd);
    }
    else {
        final = snd;
        final->next = SortedMerge(fst, snd->next);
    }
    return final;
}


void MergeSort(Element** h)
{
    Element* head = *h;
    Element* a;
    Element* b;
 
    //If length is 0 or 1, we don't sort!
    if (!head || !(head->next)) {
        return;
    }
 
    //Split the List in 2 lists
    Splitter(head, &a, &b);
 
    //Let's sort both of the "sublists"
    MergeSort(&a);
    MergeSort(&b);
 
    //Our result will be sorting together both of the lists!
    *h = SortedMerge(a, b);
}

void mergeSortList(List* list){
    
    //delete all NULL
    
    Element** temp1, **temp2;
    temp1 = &(list->head);
    temp2 = &((*temp1)->next->next);
    while((*temp1) && (*temp1)->next){
        free((*temp1)->next);
        (*temp1)->next = (*temp2);
        temp1 = &((*temp1)->next);
        temp2 = &((*temp1)->next->next);
    }
    
    MergeSort(&(list->head));
    
    Element** temp = &(list->head);
    Element** inFront = &((*temp)->next);
    while((*temp) && (*temp)->next){
      Element* ElementNull = malloc(sizeof(struct Element));
      ElementNull->data[0]='\0';
      ElementNull->next = NULL;
      (*temp)->next = ElementNull;
      (*temp)->next->next = *inFront;
      temp = &(*inFront);
      inFront = &((*inFront)->next);
    }
    //ADD ALL NULL
    list->tail = *inFront;
}




void display(List *list){
    
    if (!list->head) printf("EMPTY LIST");
    
    else{
        printf("Debut--");
        Element *temp = (Element *) malloc(sizeof(Element));
        temp = list->head;
        
        while(temp!= NULL){
            if (temp->data==NULL){
                printf("(X)--",temp->data);
            }
            else{
                printf("(%s)--",temp->data);
            }   
            temp = temp->next;
        }
    }
    printf("Fin");
    printf("\n");
}

