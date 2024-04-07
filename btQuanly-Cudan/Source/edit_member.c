#include "member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Edit the information of a member in the file based on the provided UID.
 * 
 * @param filename The name of the file in which the member's information will be edited.
 * @param updatedMember The updated information of the member.
 * 
 * @return void
 */
void editMember(const char* filename, Member updatedMember) {
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
        if (strcmp(tempUID, updatedMember.uid) == 0) {
            fprintf(tempFile, "%s,%s,%s,%s\n", updatedMember.uid, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
            found = 1;
        } else {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Member with UID %s not found.\n", updatedMember.uid);
        remove("temp.csv"); // Delete the temporary file
    } else {
        remove(filename); // Delete the original file
        rename("temp.csv", filename); // Rename the temporary file to the original name
        printf("Member with UID %s updated successfully.\n", updatedMember.uid);
    }
}
