#include <stdio.h>
#include <limits.h>
#include <math.h>

//Two's complement are not added to code. 


int convertBinaryToDecimal(long long binaryNumber);
long long convertDecimalToBinary(int decimalNumber);
int getDigits(long long n);

int main(void)
{

	long long binaryNumber = 11011;
	int decimal = convertBinaryToDecimal(binaryNumber);
	binaryNumber = convertDecimalToBinary(decimal);
	return 0;
}

int convertBinaryToDecimal(long long binaryNumber)
{
	int digits = getDigits(binaryNumber);
	printf("\nNumber of digits in this number: %d", digits);

	int decimalNumber = 0;
	long long numberOfDigits = 1;
	if (binaryNumber < 0)
		binaryNumber = (binaryNumber == LLONG_MIN) ? LLONG_MAX : -binaryNumber;
	while (binaryNumber > 0)
	{
		decimalNumber += (binaryNumber % 10) * pow(2, numberOfDigits - 1);
		binaryNumber /= 10;
		numberOfDigits++;
	}

	printf("\nDecimal Number: %d", decimalNumber);

	return decimalNumber;
}

long long convertDecimalToBinary(int decimalNumber)
{
	long long binaryNumber = 0;
	long long numberOfDigits = 1;
	int remainder = 0;
	if (decimalNumber < 0)
	{
		//two's complement.
	}
	else
	{
		while (decimalNumber > 0)
		{
			remainder = decimalNumber % 2;
			decimalNumber = decimalNumber / 2;
			binaryNumber += remainder * pow(10, numberOfDigits-1);
			numberOfDigits++;
		}
	}
	printf("\nBinary Number: %d", binaryNumber);
	return 0;
}

int getDigits(long long n)
{
	long long r = 1;
	if (n < 0)
		n = (n == LLONG_MIN) ? LLONG_MAX : -n;
	while (n > 9)
	{
		n /= 10;
		r++;
	}
	return r;
}