#include "member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Delete a member from the file based on the provided UID.
 * 
 * @param filename The name of the file from which the member will be deleted.
 * @param uid The UID of the member to be deleted.
 * 
 * @return void
 */
void deleteMember(const char* filename, const char* uid) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    FILE* tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        fclose(file);
        printf("Error opening temporary file for writing.\n");
        return;
    }

    char line[100]; // Assuming maximum length of line is 100 characters
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char tempUID[20];
        sscanf(line, "%[^,],", tempUID);
        if (strcmp(tempUID, uid) != 0) {
            fputs(line, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Member with UID %s not found.\n", uid);
        remove("temp.csv"); // Delete the temporary file
    } else {
        remove(filename); // Delete the original file
        rename("temp.csv", filename); // Rename the temporary file to the original name
        printf("Member with UID %s deleted successfully.\n", uid);
    }
}
