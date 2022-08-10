#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "bit_op.h"

int convertBinaryToDecimal(long long binaryNumber);
long long convertDecimalToBinary(int decimalNumber);

int main(void)
{

	printf("Please enter a decimal number: ");
	int decimalNumber = 0;
	scanf("%d",&decimalNumber);
	long long binaryNumber = 0;



	//Complement operation
	printf("\n------- Complement Operation ~ -------");
	decimalNumber = ~decimalNumber;
	printf("\nDecimal Number: %d",decimalNumber);
	binaryNumber = convertDecimalToBinary(decimalNumber);
	printf("\nBinary Number: %d",binaryNumber);

	printf("\n------- AND Operation & -------");
	
	printf("\nPlease enter a decimal number: ");
	scanf("%d",&decimalNumber);
	printf("Please enter a second decimal number: ");
	int decimalNumber2 = 0;
	scanf("%d",&decimalNumber2);
	binaryNumber = convertDecimalToBinary(decimalNumber & decimalNumber2);
	printf("\nBinary Number: %d",binaryNumber);

	printf("\n------- OR Operation | -------");
	binaryNumber = convertDecimalToBinary(decimalNumber | decimalNumber2);
	printf("\nBinary Number: %d",binaryNumber);


	printf("\n------- XOR Operation ^ -------");
	binaryNumber = convertDecimalToBinary(decimalNumber ^ decimalNumber2);
	printf("\nBinary Number: %d",binaryNumber);

	printf("\n------- Left Shifting << 1 -----");
	binaryNumber = convertDecimalToBinary(decimalNumber << 1);
	printf("\nBinary Number: %d",binaryNumber);

	printf("\n------- Right Shifting >> 1 -----");
	binaryNumber = convertDecimalToBinary(decimalNumber >> 1);
	printf("\nBinary Number: %d",binaryNumber);


	return 0;
}