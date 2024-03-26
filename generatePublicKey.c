#include "utilityFunctions.h"
#include <stdio.h>
#include <stdlib.h>
long long int * showAvailablePublicKeys(long long int PHI,long long int * sizeOfarrayArgument){
    long long int sizeOfValidPublicKeyArray=0;
    long long int publicKeyIndex=0;

    for(long long int i=2;i<PHI;i++){
        if(greatestCommonDivisor(i,PHI)==1){
            sizeOfValidPublicKeyArray++;
        }
    }
    long long int *validPublicKeyArray = (long long int*)malloc(sizeOfValidPublicKeyArray*sizeof(long long int));

     if (validPublicKeyArray == NULL) {
        printf("Memory allocation failed validPublicKeyArray\n");
        long long int *errorValueAdderss;
        long long int errorValue = -1;
        *sizeOfarrayArgument=0;
        errorValueAdderss = &errorValue;
        return errorValueAdderss ;
    }
    
    for(long long int i=2;i<PHI;i++){
        if(greatestCommonDivisor(i,PHI)==1){
            printf("valid public key INDEX :  %d  valid public key : %d \n",publicKeyIndex , i);
            validPublicKeyArray[publicKeyIndex] = i;
            publicKeyIndex++;
        }
    }
    *sizeOfarrayArgument = sizeOfValidPublicKeyArray;
    return validPublicKeyArray;


}