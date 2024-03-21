#include "utilityFunctions.h"
#include <stdio.h>
#include <stdlib.h>
int * showAvailablePrivateKeys(int PHI,int publicKey ,int * sizeOfarrayArgument ,int lowerLimit,int upperLimit){
    int sizeOfValidPrivateKeyArray=0;
    int privateKeyIndex=0;



    for(int i=lowerLimit;i<upperLimit;i++){
        if(((i*publicKey)%PHI)==1){
            sizeOfValidPrivateKeyArray++;
        }
    }


    int *validPrivateKeyArray = (int*)malloc(sizeOfValidPrivateKeyArray*sizeof(int));

     if (validPrivateKeyArray == NULL) {
        printf("Memory allocation failed validPrivateKeyArray\n");
        int *errorValueAdderss;
        int errorValue = -1;
        *sizeOfarrayArgument=0;
        errorValueAdderss = &errorValue;
        return errorValueAdderss ;
    }
    
    for(int i=lowerLimit;i<upperLimit;i++){//<----------------
        if(((i*publicKey)%PHI)==1){
            printf("valid Private key INDEX :  %d  valid Private key : %d \n",privateKeyIndex , i);
            validPrivateKeyArray[privateKeyIndex] = i;
            privateKeyIndex++;
        }
    }
    
    *sizeOfarrayArgument = sizeOfValidPrivateKeyArray;
    return validPrivateKeyArray;


}