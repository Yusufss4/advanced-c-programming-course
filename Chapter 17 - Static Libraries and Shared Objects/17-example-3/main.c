#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(void) {
	void *handle = NULL;
	double (*cosine)(double) = NULL; // pointer function. 
	char *error = NULL;

	handle = dlopen("/lib/x86_64-linux-gnu/lib",RTLD_LAZY);

	if (!handle) {
		fputs(dlerror(),stderr);
		exit(1);
	}

	dlerror(); // reset the previous error.

	cosine = dlsym(handle,"cos"); // laod the function into the cosine.

	if((error = dlerror()) != NULL) {
		fputs(error,stderr); 
		exit(1); // if there is an error with loading exit.
	}

	printf("%f\n", (*cosine)(2.0)); // call the function pointer.

	dlclose(handle); // unload the function.

	return 0;
}
