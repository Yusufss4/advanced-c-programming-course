// Online C compiler to run C program online
#include <stdlib.h>
#include <stdio.h>

FILE *openFile (const char *file);

int main() {
  openFile("test");
}

FILE *openFile (const char *file) {
FILE *inFile;

if ( (inFile = fopen(file,"r")) == NULL) {
    fprintf(stderr,"Can't open %s for reading.\n",file);
    exit(EXIT_FAILURE);
}
return inFile;
}