#include "member.h"
#include <stdio.h>

/**
 * @brief Print the list of members stored in the file.
 * 
 * @param filename The name of the file containing the list of members.
 * 
 * @return void
 */
void printMemberList(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[100]; // Assuming maximum length of line is 100 characters
    printf("UID,Room Number,Name,License Plate\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}
