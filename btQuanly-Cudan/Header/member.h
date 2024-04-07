#ifndef MEMBER_H
#define MEMBER_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char uid[20];           // RFID UID
    char roomNumber[10];    // Room Number
    char name[50];          // Name
    char licensePlate[20];  // License Plate
} Member;

void addMember(const char* filename, Member member);
void deleteMember(const char* filename, const char* uid);
void editMember(const char* filename, Member updatedMember);
Member searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*));
void printMemberList(const char* filename);

#endif /* MEMBER_H */
