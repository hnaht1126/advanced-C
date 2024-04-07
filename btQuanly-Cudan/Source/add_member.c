#include "member.h"
#include <stdio.h>

/**
 * @brief Add a new member to the file.
 * 
 * @param filename The name of the file to which the member will be added.
 * @param member The Member structure containing the information of the member to be added.
 * 
 * @return void
 */
void addMember(const char* filename, Member member) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }
    fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(file);
}
