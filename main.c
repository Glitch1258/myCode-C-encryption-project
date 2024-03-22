#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utilityFunctions.h"

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

            int firstPrimeNumber,secondPrimeNumber,upperLimitOfPrimeNumbers,
            lowerLimitOfPrimeNumbers,sizeOfPrimeNumberArray,indexFirstPrimeNumber,
            indexSecondPrimeNumber,sizeOfValidPublicKeysArray,publicKey,
            indexPublicKey,privateKey;

            int* primeNumberArray;
            int* validPublicKeysArray;

            long long int productOfPrimeNumbers,PHI;

            system("cls");
            printf("Generating private and public keys for enryption\n");
            printf("\n\nTo generate public keys you need to choose 2 large prime numbers\n");
            printf("This program generates prime numbers with in a given range of your choosing \n");
            printf("You need to input 2 values one for a LOWER LIMIT and another for an UPPER LIMIT of a range \n");
            printf("The program will generate all prime numbers within the given [ LOWER LIMIT --- UPPER LIMIT ]  \n");
            printf("keep in mind that we need to generate large prime numbers \n\n\n");

            printf("enter value for LOWER LIMIT of range : ");
            scanf("%d",&lowerLimitOfPrimeNumbers);
            
            printf("enter value for UPPER LIMIT of range : ");
            scanf("%d",&upperLimitOfPrimeNumbers);
            printf("\n");

            primeNumberArray = generatePrimeNumbersInRangeOf(lowerLimitOfPrimeNumbers,upperLimitOfPrimeNumbers,&sizeOfPrimeNumberArray);
          
            printf("Enter index of first primeNumber : ");
            scanf("%d",&indexFirstPrimeNumber);
            firstPrimeNumber = primeNumberArray[indexFirstPrimeNumber];

            printf("Enter index of second primeNumber : ");
            scanf("%d",&indexSecondPrimeNumber);
            secondPrimeNumber = primeNumberArray[indexSecondPrimeNumber];

            free(primeNumberArray);

            productOfPrimeNumbers = (firstPrimeNumber*secondPrimeNumber);
            PHI = ((firstPrimeNumber-1)*(secondPrimeNumber-1));

            validPublicKeysArray =  showAvailablePublicKeys(PHI,&sizeOfValidPublicKeysArray);

            printf("Enter index of chosen public key : ");
            scanf("%d",&indexPublicKey);
            publicKey = validPublicKeysArray[indexPublicKey];
            free(validPublicKeysArray);

            privateKey = generatePrivateKey(PHI,publicKey);
            printf("Yout private key : ",privateKey);



           






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
            system("cls");
            return 0;
        }


        printf("invalid input exiting ...");
        return 0 ;

    }
    

    return 0;
}
