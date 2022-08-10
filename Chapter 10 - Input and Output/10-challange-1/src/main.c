#include <stdio.h>
int readNumOfWordsInFile(const char *fileName);
int readNumOfCharsInFile(const char *fileName);

int main(int argc, char *argv[])
{

	if (argc == 2)
	{
		int numOfChars = 0;
		int numOfWords = 0;
		printf("The supplied file name is %s\n", argv[1]);
		numOfWords = readNumOfWordsInFile(argv[1]);
		numOfChars = readNumOfCharsInFile(argv[1]);
		printf("\nThe number of characters in the  file %s are : %d\n\n", argv[1], numOfChars);
		printf("\nThe number of words in the  file %s are : %d\n", argv[1], numOfWords);
	}
	else if (argc > 2)
	{
		printf("Too many arguments supplied.\n");
	}
	else
	{
		printf("--- Standart Input Mode ---\n");
		char ch = 0;
		while((ch = getchar()) != EOF) {
	    printf("%c",ch); }
		
	}
}

int readNumOfCharsInFile(const char *fileName)
{
	int numOfChars = 0;
	FILE *fp;
	char ch;

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		perror("Error in opening file");
		return (-1);
	}
	else
	{
		do
		{
			ch = fgetc(fp);
			if (ch == ' ' || ch == '\n' || ch == EOF || ch == '\r')
			{
			}
			else
			{
				numOfChars++;
				printf("%c", ch);
			}

		} while (ch != EOF);
	}

	fclose(fp);

	return numOfChars;
}

int readNumOfWordsInFile(const char *fileName)
{
	int numOfWords = 0;
	FILE *fp;
	char ch;

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		perror("Error in opening file");
		return (-1);
	}
	else
	{
		printf("\nThe content of the file %s are : ", fileName);
		do
		{
			ch = fgetc(fp);
			printf("%c", ch);
			while (ch != ' ' && ch != '\n' && ch != '\r')
			{
				//we are still in the word.
				ch = fgetc(fp);
				if (ch == EOF)
				{
					break;
				}
				printf("%c", ch);
			}
			while (ch == ' ')
			{
				//we are in the space.
				ch = fgetc(fp);
				if (ch == EOF)
				{
					break;
				}
				printf("%c", ch);
			}
			numOfWords++;

		} while (ch != EOF);
	}

	fclose(fp);

	return numOfWords;
}
