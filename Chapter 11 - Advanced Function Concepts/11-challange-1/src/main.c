#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double calculateVariance(int count, ...);

int main(void)
{
    printf("Variance -> %.2f\n", calculateVariance(4, 2.0, 4.0, 5.0, 10.0));
    return 0;
}

double calculateVariance(int count, ...)
{
    double sum = 0;
    double num = 0;
    va_list argsMean;
    va_start(argsMean, count);
    va_list argsSumMinusMean;
    va_copy(argsSumMinusMean, argsMean);

    for (int i = 0; i < count; ++i)
    {
        num = va_arg(argsMean, double);
        sum += num;
    }
    va_end(argsMean);

    double mean = sum / count;
    double diffBetweenMean = 0;

    for (int i = 0; i < count; ++i)
    {
        double num = va_arg(argsSumMinusMean, double);
        diffBetweenMean += ((num - mean) * (num - mean));
    }
    va_end(argsSumMinusMean);


    return (diffBetweenMean / (count-1));
}