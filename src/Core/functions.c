#include <stdio.h>
#include <stdlib.h>

// Defining functions context of definiontions.h

int len_string(char string[])
{
    int num = 0;
    while (string[num] != '\0')
    {
        num++;
    }
    return num;
}

char* add_strings(char string1[], char string2[])
{
    int length1 = len_string(string1);
    int length2 = len_string(string2);
    int combined_length = length1 + length2 + 1;
    
    char *new_string = (char*)malloc(combined_length);
    if (new_string == NULL) {
        return NULL;
    }

    int i = 0;
    for (int j = 0; j < length1; j++) {
        new_string[i++] = string1[j];
    }
    for (int j = 0; j < length2; j++) {
        new_string[i++] = string2[j];
    }
    new_string[i] = '\0';

    return new_string;
}

char* read_file_custom(const char *filepath)
{
    FILE *fptr = fopen(filepath, "rb");
    if (fptr == NULL) {
        return NULL;
    }
    
    fseek(fptr, 0, SEEK_END);
    long file_size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    char *buffer = (char*)malloc(file_size + 1); // +1 επειδή '\0'
    if (buffer == NULL) {
        fclose(fptr);
        return NULL;
    }
    
    char *ptr = buffer;
    int ch;
    
    while ((ch = fgetc(fptr)) != EOF) {
        *ptr = (char)ch;
        ptr++;
    }

    *ptr = '\0';

    fclose(fptr);
    return buffer;
}

char* cleanup_string(char *string)
{
    if (string == NULL) return NULL;

    int length = len_string(string);
    int w = 0;

    for (int i = 0; i < length; i++)
    {
        if (string[i] == '\r')
        {
            continue; 
        }
        
        string[w] = string[i];
        w++;
    }
    
    string[w] = '\0';

    return string;
}