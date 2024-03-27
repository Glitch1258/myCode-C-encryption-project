#include <stdio.h>
#include "myFunctions.h"
#include <stdlib.h>

void handleUSER_OPTION_2()
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
    }
    else
    {
        fseek(filePointer, 0, SEEK_END);
        long long int fileSize = ftell(filePointer);
        rewind(filePointer);

        long long int *buffer = (long long int *)malloc(((fileSize) + 1) * sizeof(long long int));

        if (buffer == NULL)
        {
            perror("Memory allocation failed for cypher text buffer");
        }
        else
        {
            printf("Enter public key of receiver : ");
            scanf("%lld", &publicKeyOfReceiver);
            printf("Enter Product Of Prime Numbers : ");
            scanf("%lld", &productOfPrimeNumbers);
            long long int index = 0;

            while ((character = fgetc(filePointer)) != EOF)
            {
                buffer[index] = modularExponentiation((long long int)character, publicKeyOfReceiver, productOfPrimeNumbers); // encrypts hata hear
                index++;
                // printf("%d",index);
            }

            fclose(filePointer);
            printf("Enter full path of file .txt along with the file name  to write the encrypted data in :");
            scanf("%c");
            scanf("%s", &plainTextFilePath);
            addExtension(plainTextFilePath);

            FILE *fp = fopen(plainTextFilePath, "wb");
            if (fp == NULL)
            {
                perror("Error creating encrypted file");
                free(buffer);
            }
            else
            {
                fwrite(buffer, sizeof(long long int), index, fp);

                free(buffer);
                fclose(fp);
            }
        }
    }
}