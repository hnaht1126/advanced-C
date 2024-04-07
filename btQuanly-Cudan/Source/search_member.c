
#include "member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef int (*SearchFunction)(const Member*, const char*);

/**
 * @brief Search for a member in the file by the given search value using the provided search function.
 * 
 * @param filename The name of the file to search in.
 * @param searchValue The value to search for (UID or license plate).
 * @param searchFunc Pointer to the search function to use (searchByUID or searchByLicensePlate).
 * @return Member Returns the found member if found, otherwise returns a dummy member with empty fields.
 */
Member searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*)) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(EXIT_FAILURE);
    }

    Member member;
    while (fscanf(file, "%19[^,],%9[^,],%49[^,],%19[^\n]\n", member.uid, member.roomNumber, member.name, member.licensePlate) != EOF) {
        if (searchFunc(&member, searchValue)) {
            fclose(file);
            return member;
        }
    }

    fclose(file);
    Member dummy = {"", "", "", ""};
    return dummy;
}
