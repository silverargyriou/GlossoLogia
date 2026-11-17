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

int num_lines(char string[])
{
    int num = 0;
    for (int i = 0; i < len_string(string); i++)
    {
        if (string[i] == '\n')
        {
            num++;
        }
    }
    return num;
}

char* get_line(char string[], int target_line) {
    if (string == NULL || target_line < 1) return NULL;

    int current_line = 1;
    char *line_start = string;
    
    if (target_line > 1) {
        for (int i = 0; string[i] != '\0'; i++) {
            if (string[i] == '\n') {
                current_line++;
                if (current_line == target_line) {
                    line_start = &string[i + 1];
                    break;
                }
            }
        }
        if (current_line < target_line) {
            return NULL; 
        }
    }
    
    int length = 0;
    while (line_start[length] != '\0' && line_start[length] != '\n' && line_start[length] != '\r') {
        length++;
    }
    
    char *new_string = (char*)malloc(length + 1);
    if (new_string == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < length; i++) {
        new_string[i] = line_start[i];
    }
    new_string[length] = '\0';

    return new_string;
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
    int in_comment = 0;

    for (int i = 0; i < length; i++)
    {
        if (string[i] == '\n')
        {
            if (string[i - 1] == '\n')
            {
            
            } else {
                string[w] = string[i];
                w++;
            }
            in_comment = 0;
            continue;
        }
        
        if (string[i] == '\r')
        {
            continue; 
        }
        
        if (!in_comment && string[i] == '/' && string[i + 1] == '/')
        {
            in_comment = 1;
            i++;
            continue;
        }
        
        if (in_comment)
        {
            continue;
        }
        
        string[w] = string[i];
        w++;
    }
    
    string[w] = '\0';

    return string;
}