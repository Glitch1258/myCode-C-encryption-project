#ifndef primeNumberGenerator
#define primeNumberGenerator
int* generatePrimeNumbersInRangeOf(int lowerLimit, int upperLimit , int *sizeOfprimeNumberArray);
int modularExponentiation(int base, int exponent, int modulus);
int greatestCommonDivisor(int a, int b);
int* showAvailablePublicKeys(int PHI,int * sizeOfarray);
int generatePrivateKey(int PHI,int privateKey);
int rsaEncryptCharacter(int plainCharacter, int publicKey, int productOfPrimeNumbers);
int rsaDecryptCharacter(int cypherCharacter, int privateKey, int productOfPrimeNumbers);
#endif