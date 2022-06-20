#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int readLinesFromFile(const char *fileName);
int isPrime(const int number);
int isEvenOrOdd(int num);

int main(int argc, char *argv[])
{

	if (argc == 2)
	{
		int numOfWords = 0;
		printf("The supplied file name is '%s'\n", argv[1]);
		numOfWords = readLinesFromFile(argv[1]);
	}
	else if (argc > 2)
	{
		printf("To many argument.");
	}
	else
	{
		printf("Required one argument. File Name");
	}
}

int readLinesFromFile(const char *fileName)
{
	FILE *filePointer;
	filePointer = fopen(fileName, "r");
	int number = 0;
	char line[100];
	if (filePointer == NULL)
	{
		perror("Error in opening file");
		return (-1);
	}
	else
	{
		printf("\n======================================\n");
		while ((fscanf(filePointer, "%s", line) == 1))
		{
			number = atoi(line);
			if (number % 2 == 0)
			{
				printf("Even number: %d\n", number);
			}
			else
			{
				printf("Odd number: %d\n", number);
			}
			if (isPrime(number))
			{
				printf("Prime number: %d\n", number);
			}
		}
		printf("\n======================================\n");
	}

	if (fclose(filePointer) != 0)
	{
		fprintf(stderr, "Error closing file\n");
	}

	return 1;
}

int isPrime(const int number)
{
	if (number < 1)
	{
		return 0;
	}
	else if (number <= 3 && number > 1)
		return 1; // as 2 and 3 are prime
	else if (number % 2 == 0 || number % 3 == 0)
		return 0; // check if number is divisible by 2 or 3
	else
	{
		unsigned int i;
		for (i = 5; i * i <= number; i += 6)
		{
			if (number % i == 0 || number % (i + 2) == 0)
				return 0;
		}
		return 1;
	}
}