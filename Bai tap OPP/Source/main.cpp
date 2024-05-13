/*
Nguyen Vo Thanh 28/4/2024
*/
#include <iostream>
#include <list>
#include <fstream>
#include "student.hpp"
#include "student_operator.hpp"

using namespace std;

int main()
{
    list<Student> database;
    //string filename = "student_database.txt";
    //loadStudentDatabase(database, filename);

    int choice;
    do
    {
        cout << "\n----------------------";
        cout << "\nQuan Ly Sinh Vien";
        cout << "\n----------------------\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Sua thong tin sinh vien\n";
        cout << "4. Tim kiem sinh vien\n";
        cout << "5. Sap xep danh sach sinh vien \n";
        cout << "6. Hien thi danh sach sinh vien\n";
        cout << "7. Luu danh sach sinh vien vao file\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            
           addStudent(database);
           break;

        case 2:
           
            deleteStudent(database);
            break;
           
        case 3:
            editStudent(database);
            break;

        case 4:

            searchStudent(database);

            break;
        case 5:
            arrangeStudent(database);
            break;
        case 6:
               
            displayStudentDatabase(database);
            break;
       
        case 7:
            saveStudentDatabase(database);
            break;

  
        case 0:
            cout << "Bye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    while (choice != 0);

    return 0;
}
