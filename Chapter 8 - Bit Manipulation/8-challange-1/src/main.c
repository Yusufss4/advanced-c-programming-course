#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "bit_op.h"

int convertBinaryToDecimal(long long binaryNumber);
long long convertDecimalToBinary(int decimalNumber);
void printInBinary(unsigned int decimalNumber);

#define BYTE_MASK 0xf

int main(void)
{

	printf("Please enter a number: ");
	unsigned int decimalNumber = 0;
	scanf("%u",&decimalNumber);
	printf("Binary form of the %u is ",decimalNumber);
	printInBinary(decimalNumber);

	printf("\nPlease enter the nth bit to set one: ");
	int bitToSet = 0;
	scanf(" %d",&bitToSet);

	int bitStatus = (decimalNumber>>bitToSet) & 1;
	printf("The %d bit is %d\n",bitToSet,bitStatus);

	unsigned int newDecimalNumber = (1<<bitToSet) | decimalNumber;
	printf("Bit set successfully.\n\n");

	printf("Old Number: %u : ",decimalNumber);
	printInBinary(decimalNumber);
	printf("\nNew Number: %u : ",newDecimalNumber);
	printInBinary(newDecimalNumber);



	return 0;
}

