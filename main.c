#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "myFunctions.h"
#include <string.h>

long long int main()
{

    printf("\n\nthis program encrypts files using the he RSA (Rivest-Shamir-Adleman) algorithm\n\n");

    while (true)

    {
        long long int USER_OPTION;
        printf("enter 1 to generate public and private keys\n");
        printf("enter 2 to encrypt a file using existing keys \n");
        printf("enter 3 to decrypt a file using existing keys \n");
        printf("enter 4 to exit \n");

        scanf("%lld", &USER_OPTION);

        if (USER_OPTION == 1)
        {
            handleUSER_OPTION_1();
        }

        else if (USER_OPTION == 2)
        {
            handleUSER_OPTION_2();
        }

        else if (USER_OPTION == 3)
        {
            handleUSER_OPTION_3();
        }

        else if (USER_OPTION == 4)
        {
            printf("exiting programm..\n");
            system("cls");
            return 0;
        }
        else
        {
            printf("invalid input exiting ...");
            return 0;
        }
    }

    // return 0;
}
