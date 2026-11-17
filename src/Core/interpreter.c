#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

char* init_interpreter(char file_data[])
{
    char *string = cleanup_string(file_data);

    printf("%s", string);

    return string;
}