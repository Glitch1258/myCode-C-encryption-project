#include "utilityFunctions.h"
#include <stdio.h>
#include <stdlib.h>
int generatePrivateKey(int PHI,int publicKey){
    for(int i=2;i<PHI;i++){
        if(((i*publicKey)%PHI)==1){
            printf("your Private key is : %d \n", i);
            return i;
        }
    }
    return -1;
}