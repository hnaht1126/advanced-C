#include <stdio.h>
#include "member.h"

/**
 * @brief Check if the given UID matches the UID of the provided member.
 * 
 * @param member Pointer to the Member structure to compare.
 * @param uid The UID to search for.
 * @return int Returns 1 if the UID matches, otherwise 0.
 */

int searchByUID(const Member* member, const char* uid) {
    return strcmp(member->uid, uid) == 0;
}

/**
 * @brief Check if the given license plate matches the license plate of the provided member.
 * 
 * @param member Pointer to the Member structure to compare.
 * @param licensePlate The license plate to search for.
 * @return int Returns 1 if the license plate matches, otherwise 0.
 */
int searchByLicensePlate(const Member* member, const char* licensePlate) {
    return strcmp(member->licensePlate, licensePlate) == 0;
}

/**
 * @brief Display the menu options and prompt the user to enter a choice.
 * 
 * @return int The choice entered by the user.
 */
int show_menu() {
    int choice;
    printf("\n=====Menu=====\n");
    printf("1. Add Member\n");
    printf("2. Delete Member\n");
    printf("3. Edit Member\n");
    printf("4. Search Member\n");
    printf("5. Print Member List\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}



int main() {
    const char* filename = "members.csv"; // File to store member data
    int choice;

    do {
        choice = show_menu(); // Display menu and get user choice
        switch (choice) {
            case 1: {
                Member newMember;
                printf("Enter UID: ");
                scanf("%s", newMember.uid);
                printf("Enter Room Number: ");
                scanf("%s", newMember.roomNumber);
                printf("Enter Name: ");
                scanf("%s", newMember.name);
                printf("Enter License Plate: ");
                scanf("%s", newMember.licensePlate);
                addMember(filename, newMember); // Add new member
                break;
            }
            case 2: {
                char uid[20];
                printf("Enter UID of member to delete: ");
                scanf("%s", uid);
                deleteMember(filename, uid); // Delete member
                break;
            }
            case 3: {
                Member updatedMember;
                printf("Enter UID of member to edit: ");
                scanf("%s", updatedMember.uid);
                printf("Enter new Room Number: ");
                scanf("%s", updatedMember.roomNumber);
                printf("Enter new Name: ");
                scanf("%s", updatedMember.name);
                printf("Enter new License Plate: ");
                scanf("%s", updatedMember.licensePlate);
                editMember(filename, updatedMember); // Edit member information
                break;
            }
            case 4: {
                char searchValue[20];
                printf("Enter UID or License Plate to search: ");
                scanf("%s", searchValue);
                Member foundMember = searchMember(filename, searchValue, searchByUID); // Search for member
                if (strcmp(foundMember.uid, "") != 0) {
                    printf("Member found:\n");
                    printf("UID: %s\nRoom Number: %s\nName: %s\nLicense Plate: %s\n", foundMember.uid, foundMember.roomNumber, foundMember.name, foundMember.licensePlate);
                } else {
                    foundMember = searchMember(filename, searchValue, searchByLicensePlate);
                    if (strcmp(foundMember.uid, "") != 0) {
                        printf("Member found:\n");
                        printf("UID: %s\nRoom Number: %s\nName: %s\nLicense Plate: %s\n", foundMember.uid, foundMember.roomNumber, foundMember.name, foundMember.licensePlate);
                    } else {
                        printf("Member with %s not found.\n", searchValue);
                    }
                }
                break;
            }
            case 5:
                printMemberList(filename); // Print member list
                break;
            case 0:
                printf("Exiting program.\n"); // Exit program
                break;
            default:
                printf("Invalid choice. Please enter again.\n"); // Invalid choice
        }
    } while (choice != 0);

    return 0;
}
