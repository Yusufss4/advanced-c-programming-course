#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int printTheLinesThatContainsSpecificChar(const char ch, const char *fileName);
int printTheLinesThatContainsSpecificChar_UsingGetLine(const char ch, const char *fileName);

int main(int argc, char *argv[])
{

	if (argc == 3)
	{
		int numOfChars = 0;
		int numOfWords = 0;
		printf("\nThe supplied character is '%c'\n", *argv[1]);
		printf("The supplied file name is '%s'\n", argv[2]);
		numOfWords = printTheLinesThatContainsSpecificChar(*argv[1], argv[2]);
		numOfWords = printTheLinesThatContainsSpecificChar_UsingGetLine(*argv[1], argv[2]);
	}
	else if (argc > 3)
	{
		printf("To many argument.");
	}
	else
	{
		printf("Required two arguments. Character and File Name");
	}
}

int printTheLinesThatContainsSpecificChar(const char ch, const char *fileName)
{
	FILE *filePointer;
	filePointer = fopen(fileName, "r");
	if (filePointer == NULL)
	{
		perror("Error in opening file");
		return (-1);
	}
	else
	{
		char buffer[255];
		char *locationOfChar = NULL;
		printf("\nReading from the file using fgets...\n");
		printf("=============================================\n");
		while (fgets(buffer, sizeof(buffer), filePointer) != NULL)
		{
			if (strchr(buffer, ch) != NULL)
			{
				printf("%s", buffer);
			}
		}
		printf("=============================================\n");
	}

	fclose(filePointer);
	return 1;
}

int printTheLinesThatContainsSpecificChar_UsingGetLine(const char ch, const char *fileName)
{
	FILE *filePointer;
	filePointer = fopen(fileName, "r");
	if (filePointer == NULL)
	{
		perror("Error in opening file");
		return (-1);
	}
	else
	{
		char *buffer = NULL;
		size_t bufsize = 255;
		size_t characters;
		int numberOfLinesFound = 0;

		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			exit(1);
		}
		printf("\nReading from the file using getline...\n");
		printf("=============================================\n");
		do
		{
			getline(&buffer, &bufsize, filePointer);
			if (strchr(buffer, ch) != NULL)
			{
				printf("%s", buffer);
				numberOfLinesFound++;
			}

		} while (!feof(filePointer) && !ferror(filePointer));
		printf("=============================================\n");
		if (numberOfLinesFound == 0)
		{
			printf("There is no line that contains the char '%c'\n", ch);
		}
		else
		{
			printf("The char '%c' found the in the %d lines.\n", ch, numberOfLinesFound);
		}
	}

	fclose(filePointer);
	return (1);
}