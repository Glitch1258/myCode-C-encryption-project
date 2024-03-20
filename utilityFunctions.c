#include "utilityFunctions.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int* generatePrimeNumbersInRangeOf(int lowerLimit, int upperLimit , int *sizeOfprimeNumberArray) { 
     bool *isPrime = (bool *)malloc((upperLimit + 1) * sizeof(bool));
    for (int i = 0; i <= upperLimit; i++)
        isPrime[i] = true;

    for (int p = 2; p * p <= upperLimit; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= upperLimit; i += p)
                isPrime[i] = false;
        }
    }

    printf("Prime numbers up to %d:\n",  upperLimit);
    int index=0;
    for (int p = lowerLimit; p <=  upperLimit; p++) {
        if (isPrime[p]){
             //printf("index : %d  number :%d\n",index,p);
            index++;
        }
           
    }

    //index++;
    *sizeOfprimeNumberArray=index;
    int* primeNumberArray = (int*)malloc(index * sizeof(int));

    if (primeNumberArray == NULL) {
        printf("Memory allocation failed\n");
        int *errorValueAdderss;
        int errorValue = -1;
        *sizeOfprimeNumberArray=0;
        errorValueAdderss = &errorValue;
        return errorValueAdderss ;
    }


    index=0;


     for (int p = lowerLimit; p <=  upperLimit; p++) {
        if (isPrime[p]){
             printf("index : %d  number :%d\n",index,p);
             primeNumberArray[index]=p;
            index++;
        }
           
    }


    printf("\n");
    free(isPrime);
    return primeNumberArray;
}