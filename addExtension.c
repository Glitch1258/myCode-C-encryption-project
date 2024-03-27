#include <stdbool.h>
#include "myFunctions.h"
#include <string.h>
#include <stdio.h>

void addExtension(char *plainTextFilePath)
{

    long long int plainTextFilePathlength = strlen(plainTextFilePath);
    if ((plainTextFilePathlength > 0) && (plainTextFilePath[plainTextFilePathlength - 1] == '\n'))
    {
        plainTextFilePath[plainTextFilePathlength - 1] = '\0';
    }
    printf("%s", plainTextFilePath);
    bool hasDotOfTXTextenstion = (plainTextFilePath[plainTextFilePathlength - 5] == '.');
    bool hasFirstTOfTXTextenstion = (plainTextFilePath[plainTextFilePathlength - 4] == 't');
    bool hasXOfTXTextenstion = (plainTextFilePath[plainTextFilePathlength - 3] == 'x');
    bool hasSecondTOfTXTextenstion = (plainTextFilePath[plainTextFilePathlength - 2] == 't');
    bool hasTXTextensionIncluded = (hasDotOfTXTextenstion && hasFirstTOfTXTextenstion &&
                                    hasXOfTXTextenstion && hasSecondTOfTXTextenstion);
    if ((!hasTXTextensionIncluded))
    {
        strcat(plainTextFilePath, ".txt");
    }
}