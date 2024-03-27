#include <stdio.h>
#include <stdlib.h>
#include "myFunctions.h"

void handleUSER_OPTION_2() {
  long long int publicKeyOfReceiver, productOfPrimeNumbers;
  printf("Encrypting plain text file using receiver's public key\n\n");
  printf("Enter full path of file along with file name and extension  to encrypt :");
  char plainTextFilePath[100], character;
  scanf("%c");
  scanf("%s", &plainTextFilePath);
  //addExtension(plainTextFilePath);

  FILE* filePointer = fopen(plainTextFilePath, "rb");  // Open file in binary mode
  if (filePointer == NULL) {
    printf("\n\nError opening plaintext file\n\n");
  } else {
    fseek(filePointer, 0, SEEK_END);
    long long int fileSize = ftell(filePointer);
    rewind(filePointer);

    long long int* buffer = (long long int*)malloc(((fileSize) + 1) * sizeof(long long int));

    if (buffer == NULL) {
      printf("\n\nMemory allocation failed for cypher text buffer\n\n");
    } else {
      printf("Enter public key of receiver : ");
      scanf("%lld", &publicKeyOfReceiver);
      printf("Enter Product Of Prime Numbers : ");
      scanf("%lld", &productOfPrimeNumbers);
      long long int index = 0;

      while ((character = fgetc(filePointer)) != EOF) {
        buffer[index] =
            modularExponentiation((long long int)character, publicKeyOfReceiver, productOfPrimeNumbers);  // encrypts hata hear
        index++;
        // printf("%d",index);
      }

      fclose(filePointer);
      printf("Enter full path of file along with name and extension of file  to write the encrypted data in :");
      scanf("%c");
      scanf("%s", &plainTextFilePath);
      //addExtension(plainTextFilePath);

      FILE* fp = fopen(plainTextFilePath, "wb");
      if (fp == NULL) {
        printf("\n\nError creating encrypted file\n\n");
        free(buffer);
      } else {
        fwrite(buffer, sizeof(long long int), index, fp);

        free(buffer);
        fclose(fp);
      }
    }
  }
}