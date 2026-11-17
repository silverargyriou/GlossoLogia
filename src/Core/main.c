#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "definitions.h"

int main(void) {
    SetConsoleOutputCP(65001);
    char filename[] = "hello";
    
    char *full_path = add_strings(filename, ".logos");
    if (full_path == NULL) return 1;
    
    char *file_data = read_file_custom(full_path);
    free(full_path);

    if (file_data == NULL) {
        printf("Αποτυχία ανάγνωσης αρχείου.\n");
        return 1;
    }
    
    char *cleanedup_data = cleanup_string(file_data);
    free(file_data);
    printf("%d %d %d\n", cleanedup_data[4], cleanedup_data[5], cleanedup_data[6]);

    return 0;
}