#include "myFunctions.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long int *generatePrimeNumbersInRangeOf(long long int lowerLimit, long long int upperLimit, long long int *sizeOfprimeNumberArray)
{
    bool *isPrime = (bool *)malloc((upperLimit + 1) * sizeof(bool));
    for (long long int i = 0; i <= upperLimit; i++)
        isPrime[i] = true;

    for (long long int p = 2; p * p <= upperLimit; p++)
    {
        if (isPrime[p] == true)
        {
            for (long long int i = p * p; i <= upperLimit; i += p)
                isPrime[i] = false;
        }
    }

    printf("Prime numbers up to %d:\n", upperLimit);
    long long int index = 0;
    for (long long int p = lowerLimit; p <= upperLimit; p++)
    {
        if (isPrime[p])
        {
            index++;
        }
    }

    *sizeOfprimeNumberArray = index;
    long long int *primeNumberArray = (long long int *)malloc(index * sizeof(long long int));

    if (primeNumberArray == NULL)
    {
        printf("Memory allocation failed primeNumberArray\n");
        long long int *errorValueAdderss;
        long long int errorValue = -1;
        *sizeOfprimeNumberArray = 0;
        errorValueAdderss = &errorValue;
        return errorValueAdderss;
    }

    index = 0;

    for (long long int p = lowerLimit; p <= upperLimit; p++)
    {
        if (isPrime[p])
        {
            printf("index : %d  number :%d\n", index, p);
            primeNumberArray[index] = p;
            index++;
        }
    }

    printf("\n");
    free(isPrime);
    return primeNumberArray;
}

long long int greatestCommonDivisor(long long int a, long long int b)
{
    if (b == 0)
    {
        return a;
    }
    return greatestCommonDivisor(b, a % b);
}

long long int modularExponentiation(long long int base, long long int exponent, long long int modulus)
{
    long long int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}
