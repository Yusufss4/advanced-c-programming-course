#include"TP3.h"

int main(int argc, char const *argv[])
{
    List *l;
    l = (List *) malloc(sizeof(List)); 
    initialize(l);
    printf("premier : ");
    display(l);
    
    insert_empty_list(l,"200220002");
    printf("\napres insertion : ");
    
    display(l);
    insert_begining_list(l,"40004400340004");
    printf("apres insertion au deb : ");
    display(l);
    printf("apres insertion a la fin: ");
    insert_end_list(l,"50005500505505");
    display(l);
    insert_after_position(l, "7000007", 3);
    printf("apres insertion a position: ");
    display(l);
    printf("apres remove: ");
    my_remove(l,3);
    display(l);
   /* sum(l);
    display(l);
    sort(l);
  
    display(l);
    exit(0);*/
    
}
