/*
Description: This header file contains declarations of funtions 
to manipulate a database of Student objects. It provides funtions to add, delete, edit,search, arrange, display, and save student records. 
*/
#ifndef _STUDENT_OPERATOR_HPP_
#define _STUDENT_OPERATOR_HPP_

#include "student.hpp"
#include <list>

using namespace std;

/* 
Function: addStudent:
Description: Adds a new student record to the database.
Input: Reference to the database list where the new student will be added 
Output: None
 */
void addStudent(list<Student> &database);
/* 
Function: deleteStudent:
    Description: Deletes a student record from the database.
    Input: Reference to the database list from which the student will be deleted.
    Output: None
 */
void deleteStudent(list<Student> &database);
/* 
Function:editStudent:
    Description: Allows editing of an existing student record in the database.
    Input: Reference to the database list containing the student records to be edited.
    Output: None 
 */
void editStudent(list<Student> &database);
/* 
Function: searchStudent:
    Description: Searches for a student record in the database.
    Input: Reference to the database list to be searched.
    Output: None
 */
void searchStudent(const list<Student> database);
/* 
Function:arrangeStudent:
    Description: Arranges the student records in the database.
    Input: Reference to the database list to be arranged.
    Output: None
 */
void arrangeStudent(list<Student> &database);
/* 
Function: displayStudentDatabase:
    Description: Displays the entire student database.
    Input: The database list to be displayed.
    Output: None
 */
void displayStudentDatabase(const list<Student> database);
/* 
Function: saveStudentDatabase:
    Description: Saves the current state of the student database to a file.
    Input: Reference to the database list to be saved.
    Output: None
 */
void saveStudentDatabase(const list<Student> &database); 

#endif

