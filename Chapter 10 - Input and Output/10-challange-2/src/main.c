#include <stdio.h>
#include <ctype.h>
#include <string.h>
int changeFileContentLowerToUpper(const char *fileName);
int saveTerminalToTheFile(const char ch, const char *fileName);

int main(int argc, char *argv[])
{

	if (argc == 2)
	{
		int numOfChars = 0;
		int numOfWords = 0;
		printf("The supplied file name is %s\n", argv[1]);
		numOfWords = changeFileContentLowerToUpper(argv[1]);
	}
	else if (argc > 2)
	{
		printf("Too many arguments supplied.\n");
	}
	else
	{
		printf("--- Standart Input Mode (Save text to file. (Append)) ---\n");
		char fileName[20];
		printf("Please enter the filename without the .txt: ");
		scanf("%s", &fileName);
		strcat(fileName,".txt");

		printf("CTRL + D for EOF\n"); 
		printf("You can start typing..\n");
		char ch = 0;
		while ((ch = getchar()) != EOF)
		{
			saveTerminalToTheFile(ch, fileName);
		}
	}
}

int saveTerminalToTheFile(const char ch, const char *fileName)
{
	FILE *filePointer;
	filePointer = fopen(fileName, "a");
	if (filePointer == NULL)
	{
		perror("Error in opening file");
		return (-1);
	}
	else
	{

		if (ch == ' ' || ch == '\n' || ch == EOF || ch == '\r')
		{
			fputc(ch, filePointer);
		}
		else
		{
			if (islower(ch))
			{
				fputc(toupper(ch), filePointer);
			}
			else
				fputc(ch, filePointer);
		}
	}

	fclose(filePointer);
}

int changeFileContentLowerToUpper(const char *fileName)
{
	int numOfChars = 0;
	FILE *oldFilePointer;
	FILE *newFilePointer;
	char ch;
	char newFileName[30] = "UP_";
	strcat(newFileName, fileName);

	newFilePointer = fopen(newFileName, "w");
	oldFilePointer = fopen(fileName, "r");
	if (oldFilePointer == NULL || newFilePointer == NULL)
	{
		perror("Error in opening file");
		return (-1);
	}
	else
	{
		ch = fgetc(oldFilePointer);
		do
		{
			if (ch == ' ' || ch == '\n' || ch == EOF || ch == '\r')
			{
				fputc(ch, newFilePointer);
			}
			else
			{
				if (islower(ch))
				{
					fputc(toupper(ch), newFilePointer);
				}
				else
					fputc(ch, newFilePointer);
			}
			ch = fgetc(oldFilePointer);
		} while (ch != EOF);
	}

	fclose(oldFilePointer);
	fclose(newFilePointer);

	remove(fileName);
	rename(newFileName, fileName);

	return 1;
}
