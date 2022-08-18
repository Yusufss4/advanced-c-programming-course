#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
	void *handle = NULL;
	char *error = NULL;

	handle = dlopen("/lib/x86_64-linux-gnu/lib", RTLD_LAZY);

	if (!handle)
	{
		fputs(dlerror(), stderr);
		exit(1);
	}

	dlerror(); // reset the previous error.

	int (*numberOfCharactersInString)(char *, char) = NULL;					  // pointer function.
	numberOfCharactersInString = dlsym(handle, "numberOfCharactersInString"); // laod the function into the cosine.

	int (*removeNonAlphaCharacters)(char *) = NULL;
	removeNonAlphaCharacters = dlsym(handle, "removeNonAlphaCharacters");

	int (*lengthOfString)(char *) = NULL;
	lengthOfString = dlsym(handle, "lengthOfString");

	int (*strConcat)(char *, char *) = NULL;
	strConcat = dlsym(handle, "strConcat");

	int (*strCopy)(char **,char *) = NULL;
	strCopy = dlsym(handle, "strCopy");

	int (*substring)(char *, int, int, char *) = NULL;
	substring = dlsym(handle, "substring");

	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1); // if there is an error with loading exit.
	}

	char *name = "Yusuf Savas";
    int lenght_of_string = 11;
    printf("Lenght of String: %d\n", (*lengthOfString)(name));

    char *name2 = "Yusuf Savas";
    char search_character = 'a';
    int freq_of_char = 2;
    printf("Frequency of a char %c: %d\n",search_character,(*numberOfCharactersInString)(name2, search_character));

    char name3[] = "!!!Yusuf11Savas&&?";
    (*removeNonAlphaCharacters)(name3);
    printf("New Name: %s\n",name3);

    #include <string.h>
    char name4[] = "Yusuf";
    char name5[] = "Savas";
    char concat_string[50];
    char copied_char[50];
   // concat_string = strConcat(name4, name5);
    printf("Concat: %s\n",(*strConcat)(name4, name5));


    char name6[] = "Yusuf Savas";
    (*substring)(name6, 6, 5, name6);
    printf("Substring: %s\n",name6);

	dlclose(handle); // unload the function.

	return 0;
}
