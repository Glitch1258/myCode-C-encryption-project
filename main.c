#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utilityFunctions.h"



// int lengthOfIntegerarray(int array[]){
//     return ( sizeof(array) / sizeof(array[0]));
// }

int main() {

    
     printf("\n\nthis program encrypts files using the he RSA (Rivest-Shamir-Adleman) algorithm\n\n");
    while(true){
        int USER_OPTION;
        printf("enter 1 to generate public and private keys\n");
        printf("enter 2 to encrypt a file using existing keys \n");
        printf("enter 3 to decrypt a file using existing keys \n");
        printf("enter 4 to exit \n");

        scanf("%d",&USER_OPTION);


        if(USER_OPTION==1){
            printf("Generating private and public keys for enryption\n");
            int upperLimit,lowerLimit;
            continue;
        }

        if(USER_OPTION==2){
            printf("Encrypting plain text file using receiver's public key\n");
            continue;
        }

        if(USER_OPTION==3){
            printf("Decrypting cypher text file using your private key\n");
            continue;
        }


        if(USER_OPTION==4){
            printf("exiting programm..\n");
            return 0;
        }


        printf("invalid input exiting ...");
        return 0 ;

    }
    

    return 0;
}
