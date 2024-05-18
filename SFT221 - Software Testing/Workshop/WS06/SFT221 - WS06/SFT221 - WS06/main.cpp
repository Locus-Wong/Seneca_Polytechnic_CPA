#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
    char testStr[] = { "This is a\n string with embedded newline character and\n12345 numbers inside it as well 67890" };
    struct StringIndex index = indexString(testStr);
    int i;
    printf("LINES\n");
    for (i = 0; i < index.numLines; i++)
    {
        printUntil(index.str, index.lineStarts[i], '\n');
        printf("\n");
    }
    printf("\nWORDS\n");
    for (i = 0; i < index.numWords; i++)
    {
        printUntilSpace(index.str, index.wordStarts[i]);
        printf("\n");
    }
    printf("\nNUMBERS\n");
    for (i = 0; i < index.numNumbers; i++)
    {
        printUntilSpace(index.str, index.numberStarts[i]);
        printf("\n");
    }
    return 0;
}
