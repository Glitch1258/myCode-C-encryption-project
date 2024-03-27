#include <stdio.h>
#include "myFunctions.h"
#include <stdlib.h>
void handleUSER_OPTION_3()
{
    long long int productOfPrimeNumbers, privateKey;
    printf("Decrypting cypher text file using your private key\n");

    char filename[100];
    char character;

    printf("Enter the path of the file to decrypt: ");
    scanf("%c");
    scanf("%s", filename);
    addExtension(filename);
    FILE *filePointer = fopen(filename, "rb");

    if (filePointer == NULL)
    {
        perror("Error opening file");
    }
    else
    {
        fseek(filePointer, 0, SEEK_END);
        long fileSize = ftell(filePointer);
        rewind(filePointer);

        long long int *buffer = (long long int *)malloc((fileSize + 1) * (sizeof(long long int)));
        if (buffer == NULL)
        {
            perror("Memory allocation failed for Decryption buffer");
        }
        else
        {

            fread(buffer, sizeof(long long int), fileSize, filePointer);
            fclose(filePointer);

            printf("Enter the private Key : ");
            scanf("%lld", &privateKey);
            printf("Enter the product of prime numbers Key: ");
            scanf("%lld", &productOfPrimeNumbers);

            printf("Enter full path of file .txt along with the file name  to write the decrypted data in :");
            scanf("%c");
            scanf("%s", &filename);
            addExtension(filename);
            filePointer = fopen(filename, "wb");

            long long int index = 0;
            for (int i = 0; i < fileSize / sizeof(long long int); i++)
            {
                char decrypted_char = (char)modularExponentiation(buffer[i], privateKey, productOfPrimeNumbers);
                printf("%c", decrypted_char);
                fprintf(filePointer, "%c", decrypted_char);
            }
        }
    }
}