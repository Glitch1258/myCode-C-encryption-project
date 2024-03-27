#include "myFunctions.h"
#include <stdio.h>
long long int generatePrivateKey(long long int PHI, long long int publicKey)
{
    for (long long int i = 2; i < PHI; i++)
    {
        if (((i * publicKey) % PHI) == 1)
        {
            printf("your Private key is : %d \n", i);
            return i;
        }
    }
    return -1;
}