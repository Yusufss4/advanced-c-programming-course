#include <stdio.h>
#include <math.h>

long long convertDecimalToBinary(int n);

int main() {
   int n = 0;
   long long result = 0;

   printf("Enter a decimal number: ");
   scanf("%d", &n);
   result = convertDecimalToBinary(n);
   printf("%d in decimal = %lld to binary", n , result);
   return 0;
}

long long convertDecimalToBinary(int n){
   long long binaryNumber = 0;
   int remainder, i=1;

   while(n != 0) {
     remainder = n%2;
     n = n / 2;
     binaryNumber += remainder * i;
     i = i * 10;
   }

   return binaryNumber;

}
