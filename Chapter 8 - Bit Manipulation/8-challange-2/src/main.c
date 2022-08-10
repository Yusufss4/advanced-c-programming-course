#include <stdio.h>
#include <stdbool.h> //C99, defines bool, true, false

/* is opaque     */
#define OPAQUE 1
#define TRANSPARENT 0

/* is border shown     */
#define BORDER_SHOWN 0
#define BORDER_HIDDEN 1

/* line styles     */
#define SOLID 0
#define DOTTED 1
#define DASHED 2

/* primary colors  */
#define BLUE 4
#define GREEN 2
#define RED 1

/* mixed colors    */
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char *colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

typedef struct onScreenBox
{
	bool isOpaque : OPAQUE;
	unsigned int fillColor : YELLOW;
	unsigned int : 4;
	bool isBorderHidden : BORDER_HIDDEN;
	unsigned int borderColor : CYAN;
	unsigned int borderStyle : DASHED;
	unsigned int : 2;

} onScreenBox;

void printBoxSettings(const onScreenBox *box);

int main()
{
	onScreenBox myBox = {
		.isOpaque = 1,
		.fillColor = 2,
		.isBorderHidden = 0,
		.borderColor = 2,
		.borderStyle = 1};

	printf("Size of box is %lu bytes\n", sizeof(myBox));

	printf("\n --- Original box settings. ---\n");
	printBoxSettings(&myBox);

	myBox.isOpaque = TRANSPARENT;
	myBox.fillColor = RED;
	myBox.isBorderHidden = BORDER_HIDDEN;
	printf("\n --- Changed box settings. ---\n");
	printBoxSettings(&myBox);

	return 1;
}

void printBoxSettings(const onScreenBox *box)
{
	printf("Box is %s.\n", box->isOpaque == true ? "opaque" : "transparent");
	printf("The fill color is %s.\n", colors[box->fillColor]);
	if (box->isBorderHidden == BORDER_SHOWN)
	{
		printf("Border is shown\n");
		printf("The border color is %s.\n", colors[box->borderColor]);
		printf("The border style is");

		switch (box->borderStyle)
		{
		case SOLID:
			printf("solid.\n");
			break;
		case DOTTED:
			printf("solid.\n");
			break;
		case DASHED:
			printf("solid.\n");
			break;
		default:
			printf("unknown type.\n");
		}
	}
	else
	{
		printf("Border is hidden.");
	}
}