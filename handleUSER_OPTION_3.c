#include <stdio.h>
#include <stdlib.h>
#include "myFunctions.h"
void handleUSER_OPTION_3() {
  long long int productOfPrimeNumbers, privateKey;
  printf("Decrypting cypher text file using your private key\n");

  char filename[100];
  char character;

  printf("Enter full path of file along with name and extension of file to decrypt: ");
  scanf("%c");
  scanf("%s", filename);
  //addExtension(filename);
  FILE* filePointer = fopen(filename, "rb");

  if (filePointer == NULL) {
    printf("\n\nError opening file\n\n");
  } else {
    fseek(filePointer, 0, SEEK_END);
    long fileSize = ftell(filePointer);
    rewind(filePointer);

    long long int* buffer = (long long int*)malloc((fileSize + 1) * (sizeof(long long int)));
    if (buffer == NULL) {
      printf("\n\nMemory allocation failed for Decryption buffer\n\n");
    } else {
      fread(buffer, sizeof(long long int), fileSize, filePointer);
      

      printf("Enter the private Key : ");
      scanf("%lld", &privateKey);
      printf("Enter the product of prime numbers Key: ");
      scanf("%lld", &productOfPrimeNumbers);

      printf("Enter full path of file along with name and extension of file  to write the decrypted data in :");
      scanf("%c");
      scanf("%s", &filename);
      //addExtension(filename);
      filePointer = fopen(filename, "wb");

      long long int index = 0;
      for (int i = 0; i < fileSize / sizeof(long long int); i++) {
        char decrypted_char = (char)modularExponentiation(buffer[i], privateKey, productOfPrimeNumbers);
        printf("%c", decrypted_char);
        fprintf(filePointer, "%c", decrypted_char);
      }
      fclose(filePointer);
    }
  }
}