#include "bit_op.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

int convertBinaryToDecimal(long long binaryNumber)
{

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
        //two's complement. Not finished.
        decimalNumber = decimalNumber*(-1);
        binaryNumber = convertDecimalToBinary(decimalNumber);
        binaryNumber *= -1; 
    }
    else
    {
        while (decimalNumber > 0)
        {
            remainder = decimalNumber % 2;
            decimalNumber = decimalNumber / 2;
            binaryNumber += remainder * pow(10, numberOfDigits - 1);
            numberOfDigits++;
        }
    }
    printf("\nDebug: Binary Number: %d", binaryNumber);
    return binaryNumber;
}