#include "utilityFunctions.h"
#include <stdio.h>
#include <stdlib.h>
int * showAvailablePublicKeys(int PHI,int * sizeOfarrayArgument){
    int sizeOfValidPublicKeyArray=0;
    int publicKeyIndex=0;

    for(int i=2;i<PHI;i++){
        if(greatestCommonDivisor(i,PHI)==1){
            sizeOfValidPublicKeyArray++;
        }
    }
    int *validPublicKeyArray = (int*)malloc(sizeOfValidPublicKeyArray*sizeof(int));

     if (validPublicKeyArray == NULL) {
        printf("Memory allocation failed validPublicKeyArray\n");
        int *errorValueAdderss;
        int errorValue = -1;
        *sizeOfarrayArgument=0;
        errorValueAdderss = &errorValue;
        return errorValueAdderss ;
    }
    
    for(int i=2;i<PHI;i++){
        if(greatestCommonDivisor(i,PHI)==1){
            printf("valid public key INDEX :  %d  valid public key : %d \n",publicKeyIndex , i);
            validPublicKeyArray[publicKeyIndex] = i;
            publicKeyIndex++;
        }
    }
    *sizeOfarrayArgument = sizeOfValidPublicKeyArray;
    return validPublicKeyArray;


}