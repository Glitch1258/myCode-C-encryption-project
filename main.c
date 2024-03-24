#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utilityFunctions.h"
#include <string.h>

int main() {
    
     printf("\n\nthis program encrypts files using the he RSA (Rivest-Shamir-Adleman) algorithm\n\n");
     
     while(true){
        //system("cls"); needs to stay commented out to make sure error messages from code is visible in console
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
            char saveInLocalStorage;

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
            system("cls");

            primeNumberArray = generatePrimeNumbersInRangeOf(lowerLimitOfPrimeNumbers,upperLimitOfPrimeNumbers,&sizeOfPrimeNumberArray);
          
            printf("Enter index of first primeNumber : ");
            scanf("%d",&indexFirstPrimeNumber);
            firstPrimeNumber = primeNumberArray[indexFirstPrimeNumber];

            printf("Enter index of second primeNumber : ");
            scanf("%d",&indexSecondPrimeNumber);
            secondPrimeNumber = primeNumberArray[indexSecondPrimeNumber];
            free(primeNumberArray);
            system("cls");

            productOfPrimeNumbers = (firstPrimeNumber*secondPrimeNumber);
            PHI = ((firstPrimeNumber-1)*(secondPrimeNumber-1));

            validPublicKeysArray =  showAvailablePublicKeys(PHI,&sizeOfValidPublicKeysArray);

            printf("Enter index of chosen public key : ");
            scanf("%d",&indexPublicKey);
            publicKey = validPublicKeysArray[indexPublicKey];
            free(validPublicKeysArray);
            system("cls"); 
           

            privateKey = generatePrivateKey(PHI,publicKey);
            //printf("Your private key : %d\n",privateKey);
            //----------------------------------------------------
            printf(" do you want to save keys in local storage ?\n press y for yes and n for no\n");
            //saveInLocalStorage = getchar();
            scanf(" %c",&saveInLocalStorage);
            scanf("%c");

            if(saveInLocalStorage=='y'||saveInLocalStorage=='Y'){

                printf("enter name of file :  ");
                char filename[30];
                fgets(filename, sizeof(filename), stdin);
                int fileNameLength = strlen(filename);

                if ((fileNameLength > 0) && (filename[fileNameLength - 1] == '\n')){
                    filename[fileNameLength - 1] = '\0';
                }

                strcat(filename, ".txt");
                                    
                FILE *filePointer = fopen(filename,"w");
                if(filePointer==NULL){
                    perror("Error opening file");
                    continue;
                    }else{
                         fprintf(filePointer, "%lld", productOfPrimeNumbers);
                         putc('-', filePointer);
                         fprintf(filePointer, "%d", privateKey);
                         putc('-', filePointer);
                         fprintf(filePointer, "%d", publicKey);
                         putc('\n', filePointer);

                         fprintf(filePointer, "product Of prime numbers [n] = %lld\n", productOfPrimeNumbers);
                         fprintf(filePointer, "private key = %d\n", privateKey);
                         fprintf(filePointer, "public key = %d\n", publicKey);
                         fclose(filePointer);
                         }

            }else if (saveInLocalStorage=='n'||saveInLocalStorage=='N'){
                printf("exiting without saving keys \n");
                continue;

            }else{
                printf("Invalid input no action can be taken based on it\n");
            }

            continue;
        }

        if(USER_OPTION==2){
            printf("Encrypting plain text file using receiver's public key\n");
            printf("Enter full path of file .txt along with the file name  to encrypt :");
            char plainTextFilePath[100];
            scanf("%c");
            fgets(plainTextFilePath,sizeof(plainTextFilePath),stdin);
            int plainTextFilePathlength = strlen(plainTextFilePath);
            if((plainTextFilePathlength>0)&&(plainTextFilePath[plainTextFilePathlength-1]=='\n')){
                plainTextFilePath[plainTextFilePathlength-1]='\0';
            }
            bool hasDotOfTXTextenstion = (plainTextFilePath[plainTextFilePathlength-5]=='.');
            bool hasFirstTOfTXTextenstion = (plainTextFilePath[plainTextFilePathlength-4]=='t');
            bool hasXOfTXTextenstion = (plainTextFilePath[plainTextFilePathlength-3]=='x');
            bool hasSecondTOfTXTextenstion = (plainTextFilePath[plainTextFilePathlength-2]=='t');
            bool hasTXTextensionIncluded = (hasDotOfTXTextenstion && hasFirstTOfTXTextenstion &&
            hasXOfTXTextenstion && hasSecondTOfTXTextenstion);
            if(!hasTXTextensionIncluded){
                strcat(plainTextFilePath,".txt");
            }

            FILE *filePointer = fopen(plainTextFilePath, "r"); 
            if (filePointer == NULL)
            {
                perror("Error opening file");
                return -1;
            }

            fseek(filePointer, 0, SEEK_END);     
            long fileSize = ftell(filePointer); 
            rewind(filePointer);               

            char *buffer = (char *)malloc(fileSize + 1); 
            if (buffer == NULL)
            {
                perror("Memory allocation failed");
                return -1;
            }
            
            fread(buffer, 1, fileSize, filePointer); 
            buffer[fileSize] = '\0';
            for(int i=0;buffer[i]!='\0';i++){
                int cypherCode =  (int)buffer[i];
                cypherCode = rsaEncryptCharacter(cypherCode,  7207,  7387) ;
                 printf("%c",buffer[i]);
                 printf("%d",cypherCode);
                 printf("%c ",(char)rsaDecryptCharacter(cypherCode,3207, 7387));
            }
             //fwrite(buffer, 1, sizeof(buffer) - 1, filePointer);          
            //printf("%s", buffer);             
            free(buffer); 
            fclose(filePointer); 
            return 0;

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


        printf("invalid input exiting ...");;
        return 0 ;

    }
    

    return 0;
}
