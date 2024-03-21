#ifndef primeNumberGenerator
#define primeNumberGenerator
int* generatePrimeNumbersInRangeOf(int lowerLimit, int upperLimit , int *sizeOfprimeNumberArray);
int mod_exp(int base, int exp, int mod);
int greatestCommonDivisor(int a, int b);
int* showAvailablePublicKeys(int PHI,int * sizeOfarray);
int* showAvailablePrivateKeys(int PHI,int privateKey,int * sizeOfarrayArgument);
#endif