#ifndef primeNumberGenerator
#define primeNumberGenerator
long long int* generatePrimeNumbersInRangeOf(long long int lowerLimit, long long int upperLimit , long long int *sizeOfprimeNumberArray);
long long int modularExponentiation(long long int base, long long int exponent, long long int modulus);
long long int greatestCommonDivisor(long long int a, long long int b);
long long int* showAvailablePublicKeys(long long int PHI,long long int * sizeOfarray);
long long int generatePrivateKey(long long int PHI,long long int privateKey);
long long int rsaEncryptCharacter(long long int plainCharacter, long long int publicKey, long long int productOfPrimeNumbers);
long long int rsaDecryptCharacter(long long int cypherCharacter, long long int privateKey, long long int productOfPrimeNumbers);
void addExtension(char *plainTextFilePath);
#endif