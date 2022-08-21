#include <stdlib.h>
#include <stdio.h>

#include <dlfcn.h>

void checkForError() {

  char *error = NULL;

  if ((error = dlerror()) != NULL)  {
       fputs(error, stderr);
       exit(1);
  }
}

int main()
{
    void *handle = NULL;

    // set up function pointers
    int (*numChars) (char *, char) = NULL;
    int (*removeNonAlpha) (char *) = NULL;
    int (*lengthStr) (char *) = NULL;
    int (*strConcat) (char *, char *) = NULL;
    int (*strCopy) (char *, char *) = NULL;
    int (*substring) (char *, int, int, char *) = NULL;

    char temp[] = "jason &&''''Fedin";
    char temp2[] = "apple";
    char temp3[100];

    handle = dlopen("../libStringFunctions/libStringFunctions.dll", RTLD_LAZY);

    if (!handle) {
    	fputs (dlerror(), stderr);
        exit(1);
    }

    dlerror();

    numChars = dlsym(handle, "numberOfCharactersInString");
    checkForError();
    printf("Number of 'p's in apples is %d\n", (*numChars)(temp2, 'p'));

    removeNonAlpha = dlsym(handle, "removeNonAlphaCharacters");
    checkForError();
    (*removeNonAlpha) (temp);
    printf("String temp with alpha characters removed is: %s\n", temp);

    lengthStr = dlsym(handle, "lengthOfString");
    checkForError();
    printf("String temp length is: %d\n", (*lengthStr) (temp));

    strConcat = dlsym(handle, "strConcat");
    checkForError();
    (*strConcat) (temp, temp2);
    printf("String concatenated with string2 is: %s\n", temp);

    strCopy = dlsym(handle, "strCopy");
    checkForError();
    (*strCopy) (temp2, temp3);
    printf("String copied is: %s\n", temp3);

    substring = dlsym(handle, "substring");
    checkForError();
    (*substring) (temp, 3, 8, temp3);
    printf("Substring is: %s\n", temp3);

    dlclose(handle);

    return 0;
}

