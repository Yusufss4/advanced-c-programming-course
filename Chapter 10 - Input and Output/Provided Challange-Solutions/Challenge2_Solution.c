#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convertCase(FILE *fptr, const char *path);

int main()
{
    /* File pointer to hold reference of input file */
    FILE *fPtr = NULL;
    char path[100];

    printf("Enter path of source file: ");
    scanf("%s", path);

    fPtr = fopen(path, "r");

     /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    convertCase(fPtr, path);

    return 0;
}

void convertCase(FILE *fptr, const char *path)
{
    FILE *dest = NULL;
    char ch = '\0';

    // Temporary file to store result
    dest = fopen("temp.txt", "w");

     // If unable to create temporary file
    if (dest == NULL)
    {
        printf("Unable to create temporary file.");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }

    /* Repeat till end of file. */
    while ( (ch = fgetc(fptr)) != EOF)
    {
        /*
         * If current character is uppercase then toggle
         * it to lowercase and vice versa.
         */
        if (isupper(ch))
            ch = tolower(ch);
        else if (islower(ch))
            ch = toupper(ch);

        // Print toggled character to destination file.
        fputc(ch, dest);
    }

    /* Close all files to release resource */
    fclose(fptr);
    fclose(dest);

    /* Delete original source file */
    remove(path);

    /* Rename temporary file as original file */
    rename("temp.txt", path);
}
