#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utilityFunctions.h"
#include <string.h>

long long int main()
{

    printf("\n\nthis program encrypts files using the he RSA (Rivest-Shamir-Adleman) algorithm\n\n");

    while (true)
    {
        long long int USER_OPTION;
        printf("enter 1 to generate public and private keys\n");
        printf("enter 2 to encrypt a file using existing keys \n");
        printf("enter 3 to decrypt a file using existing keys \n");
        printf("enter 4 to exit \n");

        scanf("%lld", &USER_OPTION);

        if (USER_OPTION == 1)
        {

            long long int firstPrimeNumber, secondPrimeNumber, upperLimitOfPrimeNumbers,
                lowerLimitOfPrimeNumbers, sizeOfPrimeNumberArray, indexFirstPrimeNumber,
                indexSecondPrimeNumber, sizeOfValidPublicKeysArray, publicKey,
                indexPublicKey, privateKey;

            long long int *primeNumberArray;
            long long int *validPublicKeysArray;
            char saveInLocalStorage;

            long long int productOfPrimeNumbers, PHI;

            system("cls");
            printf("Generating private and public keys for enryption\n");
            printf("\n\nTo generate public keys you need to choose 2 large prime numbers\n");
            printf("This program generates prime numbers with in a given range of your choosing \n");
            printf("You need to input 2 values one for a LOWER LIMIT and another for an UPPER LIMIT of a range \n");
            printf("The program will generate all prime numbers within the given [ LOWER LIMIT --- UPPER LIMIT ]  \n");
            printf("keep in mind that we need to generate large prime numbers \n\n\n");

            printf("enter value for LOWER LIMIT of range : ");
            scanf("%lld", &lowerLimitOfPrimeNumbers);

            printf("enter value for UPPER LIMIT of range : ");
            scanf("%lld", &upperLimitOfPrimeNumbers);
            printf("\n");
            system("cls");

            primeNumberArray = generatePrimeNumbersInRangeOf(lowerLimitOfPrimeNumbers, upperLimitOfPrimeNumbers, &sizeOfPrimeNumberArray);

            printf("Enter index of first primeNumber : ");
            scanf("%lld", &indexFirstPrimeNumber);
            firstPrimeNumber = primeNumberArray[indexFirstPrimeNumber];

            printf("Enter index of second primeNumber : ");
            scanf("%lld", &indexSecondPrimeNumber);
            secondPrimeNumber = primeNumberArray[indexSecondPrimeNumber];
            free(primeNumberArray);
            system("cls");

            productOfPrimeNumbers = (firstPrimeNumber * secondPrimeNumber);
            PHI = ((firstPrimeNumber - 1) * (secondPrimeNumber - 1));

            validPublicKeysArray = showAvailablePublicKeys(PHI, &sizeOfValidPublicKeysArray);

            printf("Enter index of chosen public key : ");
            scanf("%lld", &indexPublicKey);
            publicKey = validPublicKeysArray[indexPublicKey];
            free(validPublicKeysArray);
            system("cls");

            privateKey = generatePrivateKey(PHI, publicKey);
            printf(" do you want to save keys in local storage ?\n press y for yes and n for no\n");
            scanf(" %c", &saveInLocalStorage);
            scanf("%c");

            if (saveInLocalStorage == 'y' || saveInLocalStorage == 'Y')
            {

                printf("enter name of file :  ");
                char filename[30];
                fgets(filename, sizeof(filename), stdin);
                long long int fileNameLength = strlen(filename);

                if ((fileNameLength > 0) && (filename[fileNameLength - 1] == '\n'))
                {
                    filename[fileNameLength - 1] = '\0';
                }

                strcat(filename, ".txt");

                FILE *filePointer = fopen(filename, "w");
                if (filePointer == NULL)
                {
                    perror("Error opening file");
                    continue;
                }
                else
                {
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
            }
            else if (saveInLocalStorage == 'n' || saveInLocalStorage == 'N')
            {
                printf("exiting without saving keys \n");
                continue;
            }
            else
            {
                printf("Invalid input no action can be taken based on it\n");
            }

            continue;
        }

        else if (USER_OPTION == 2)
        {
            long long int publicKeyOfReceiver, productOfPrimeNumbers;
            printf("Encrypting plain text file using receiver's public key\n\n");
            printf("Enter full path of file .txt along with the file name  to encrypt :");
            char plainTextFilePath[100], character;
            scanf("%c");
            fgets(plainTextFilePath, sizeof(plainTextFilePath), stdin);
            addExtension(plainTextFilePath);

            FILE *filePointer = fopen(plainTextFilePath, "rb"); // Open file in binary mode
            if (filePointer == NULL)
            {
                perror("Error opening plaintext file");
                continue;
            }

            fseek(filePointer, 0, SEEK_END);
            long long int fileSize = ftell(filePointer);
            rewind(filePointer);

            long long int *buffer = (long long int *)malloc(((fileSize) + 1) * sizeof(long long int));

            if (buffer == NULL)
            {
                perror("Memory allocation failed for cypher text buffer");
                continue;
            }

            printf("Enter public key of receiver : ");
            scanf("%lld", &publicKeyOfReceiver);
            printf("Enter Product Of Prime Numbers : ");
            scanf("%lld", &productOfPrimeNumbers);
            long long int index = 0;

            while ((character = fgetc(filePointer)) != EOF)
            {
                buffer[index] = modularExponentiation((long long int)character, publicKeyOfReceiver, productOfPrimeNumbers); // encrypts hata hear
                index++;
            }

            fclose(filePointer);

            FILE *fp = fopen(plainTextFilePath, "wb");
            if (fp == NULL)
            {
                perror("Error creating encrypted file");
                free(buffer);
                continue;
            }

            fwrite(buffer, sizeof(long long int), index, fp);

            free(buffer);
            fclose(fp);

            continue;
        }

        else if (USER_OPTION == 3)
        {
            long long int productOfPrimeNumbers, privateKey;
            printf("Decrypting cypher text file using your private key\n");

            char filename[100];
            char character;

            printf("Enter the name of the file: ");
            scanf("%s", filename);
            scanf("%c");
            addExtension(filename);
            FILE *filePointer = fopen(filename, "rb");

            if (filePointer == NULL)
            {
                perror("Error opening file");
                continue;
            }

            fseek(filePointer, 0, SEEK_END);
            long fileSize = ftell(filePointer);
            rewind(filePointer);

            long long int *buffer = (long long int *)malloc((fileSize + 1) * (sizeof(long long int)));

            if (buffer == NULL)
            {
                perror("Memory allocation failed for Decryption buffer");
                continue;
            }
            fread(buffer, sizeof(long long int), fileSize, filePointer);
            fclose(filePointer);
            filePointer = fopen(filename, "wb");

            printf("Enter the private Key : ");
            scanf("%lld", &privateKey);
            printf("Enter the product of prime numbers Key: ");
            scanf("%lld", &productOfPrimeNumbers);
            long long int index = 0;

            for (int i = 0; i < fileSize / sizeof(long long int); i++)
            {
                char decrypted_char = (char)modularExponentiation(buffer[i], privateKey, productOfPrimeNumbers);
                printf("%c", decrypted_char);
                fprintf(filePointer, "%c", decrypted_char);
            }

            continue;
        }

        else if (USER_OPTION == 4)
        {
            printf("exiting programm..\n");
            system("cls");
            return 0;
        }
        else
        {
            printf("invalid input exiting ...");
            return 0;
        }
    }

    // return 0;
}
