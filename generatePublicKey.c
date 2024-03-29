#include <stdio.h>
#include <stdlib.h>
#include "myFunctions.h"
long long int* showAvailablePublicKeys(long long int PHI, long long int* sizeOfarrayArgument) {
  long long int sizeOfValidPublicKeyArray = 0;
  long long int publicKeyIndex = 0;
//<changed>
  long long int maximumNumberOfPublicKeys,minimumValueOfPrivateKey;
  int USER_INPUT_FOR_KEYS;
//</changed>
printf("\nCalculating number of possible public keys...\n");
  for (long long int i = 2; i < PHI; i++) {
    if (greatestCommonDivisor(i, PHI) == 1) {
      sizeOfValidPublicKeyArray++;
    }
  }
//<changed>
  generatePublicKeys:
  printf("%lld possible public keys can be generated\n",sizeOfValidPublicKeyArray);
  printf("Press 1 to generate all possible public keys : \n");
  printf("Press 2 to limit the number of possible public keys generated : \n");
  scanf("%d",&USER_INPUT_FOR_KEYS);
  if(USER_INPUT_FOR_KEYS==1){
    minimumValueOfPrivateKey=2;

  }else if(USER_INPUT_FOR_KEYS==2){
    printf("Enter maximum number of public keys to be generated : ");
    scanf("%lld",&maximumNumberOfPublicKeys);

    if(maximumNumberOfPublicKeys>PHI){
      maximumNumberOfPublicKeys=PHI;
    }
    sizeOfValidPublicKeyArray = maximumNumberOfPublicKeys;

    printf("Enter minimum value  of public key to be generated : ");
    scanf("%lld",&minimumValueOfPrivateKey);
    if(minimumValueOfPrivateKey<2){
      minimumValueOfPrivateKey=2;
    }

  }else{
    printf("invalid input");
    goto generatePublicKeys;

  }

//</changed>
  long long int* validPublicKeyArray = (long long int*)malloc(sizeOfValidPublicKeyArray * sizeof(long long int));

  if (validPublicKeyArray == NULL) {
    printf("Memory allocation failed validPublicKeyArray\n");
    long long int* errorValueAdderss;
    long long int errorValue = -1;
    *sizeOfarrayArgument = 0;
    errorValueAdderss = &errorValue;
    return errorValueAdderss;
  }
//<changed>
  for (long long int i = minimumValueOfPrivateKey; i < PHI; i++) {
//</changed>
    if (greatestCommonDivisor(i, PHI) == 1) {
      printf("valid public key INDEX :  %d  valid public key : %d \n", publicKeyIndex, i);
      validPublicKeyArray[publicKeyIndex] = i;
      publicKeyIndex++;
//<changed>
      if(publicKeyIndex>maximumNumberOfPublicKeys){break;};
//</changed>
    }
  }
  *sizeOfarrayArgument = sizeOfValidPublicKeyArray;
  return validPublicKeyArray;
}