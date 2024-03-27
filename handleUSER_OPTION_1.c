#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myFunctions.h"

void handleUSER_OPTION_1() {
  long long int firstPrimeNumber, secondPrimeNumber, upperLimitOfPrimeNumbers, lowerLimitOfPrimeNumbers, sizeOfPrimeNumberArray,
      indexFirstPrimeNumber, indexSecondPrimeNumber, sizeOfValidPublicKeysArray, publicKey, indexPublicKey, privateKey;

  long long int* primeNumberArray;
  long long int* validPublicKeysArray;
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

  if (saveInLocalStorage == 'y' || saveInLocalStorage == 'Y') {
    printf("Enter full path of file along with name and extension of file :  ");
    char filename[30];
    fgets(filename, sizeof(filename), stdin);
    long long int fileNameLength = strlen(filename);

    if ((fileNameLength > 0) && (filename[fileNameLength - 1] == '\n')) {
      filename[fileNameLength - 1] = '\0';
    }

    //addExtension(filename);

    FILE* filePointer = fopen(filename, "w");
    if (filePointer == NULL) {
      printf("\n\nError opening file\n\n");
    } else {
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
  } else if (saveInLocalStorage == 'n' || saveInLocalStorage == 'N') {
    printf("exiting without saving keys \n");
  } else {
    printf("Invalid input no action can be taken based on it\n");
  }
}