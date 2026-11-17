#pragma once
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

char* init_interpreter(char file_data[]);
int len_string(char string[]);
int num_lines(char string[]);
char* get_line(char string[], int line);
char* add_strings(char string1[], char string2[]);
char* read_file_custom(const char *filepath);
char* cleanup_string(char *string);

#endif