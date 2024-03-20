#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "utilityFunctions.h"



// int lengthOfIntegerarray(int array[]){
//     return ( sizeof(array) / sizeof(array[0]));
// }

int main() {
    int n,m;
    // printf("Enter the value of n: ");
    // scanf("%d", &n);


    // printf("Enter the value of m: ");
    // scanf("%d", &m);

    // printf("enteren n %d\n",n);
    // printf("enteren m %d\n",m);

    n=30;
    m=50;
    int sss;
    int *array = generatePrimeNumbersInRangeOf(n,m,&sss);

    printf("======================================\n");
    for(int i=0;i<sss;i++){
        printf("in %d ===== %d\n",i,array[i]);
    }

    printf("Enter the value of n: as");
    scanf("%d", &n);


    return 0;
}
