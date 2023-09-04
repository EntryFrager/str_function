#include <stdio.h>
#include <string.h>
#include <TXLib.h>
#include <stdlib.h>

int main ()
{
    char* filename = "str.txt";
    FILE* fp = fopen (filename, "r");
    char* str5 = (char *) malloc (5 * sizeof(char));
    size_t byte = 5;
    getline(&str5, &byte, fp);
}
