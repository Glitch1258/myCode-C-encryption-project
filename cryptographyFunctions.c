#include "utilityFunctions.h"
#include <stdio.h>
int showAvailablePublicKeys(int PHI,int * sizeOfarray){
    int numberOfKeys=0;
    for(int i=2;i<PHI;i++){
        if(greatestCommonDivisor(i,PHI)==1){
            numberOfKeys++;
        }
        
    }
    sizeOfarray = numberOfKeys;

}