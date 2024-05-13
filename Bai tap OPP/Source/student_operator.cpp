/*
Description: Functional functions
*/


#include "student_operator.hpp"

#include <iostream>
#include <fstream>
//#include <cassert>

using namespace std;

/*
Function: add Student
Description:
Input:
Output:
*/

void addStudent(list<Student>& database)
{
    while (true)
    {
        string name;
        int age;
        Gender gender;
        double math;
        double physic;
        double chemical;


        cout << "Nhap ten: " ;
        cin >> name;

        cout << "Nhap tuoi: ";
        cin >> age;

        int g; // bien so sanh de xac dinh gender
        do
        {
            cout << "Nhap gioi tinh: (0 - MALE / 1 - FEMALE)" ;
            cin >> g;
            if (g == 0)
            {
                gender = MALE;
            }
            else if (g == 1)
            {
                gender = FEMALE;
            }
        } while (g != 0 && g != 1);

        /* cassert */

        do
        {
            cout << "Nhap diem toan: ";
            cin >> math;
            if (math < 0 || math > 10)
            {
                cout << "Math score must form 0 to 10" << endl;
            }

        } while (math < 0 || math > 10);

        do
        {
            cout << "Nhap diem ly: " ;
            cin >> physic;
            if (physic < 0 || physic > 10)
            {
                cout << "Physic score must form 0 to 10" << endl;
            }

        } while (physic < 0 || physic > 10);

        do
        {
            cout << "Nhap diem Hoa: ";
            cin >> chemical;
            if (chemical < 0 || chemical > 10)
            {
                cout << "Chemical score must form 0 to 10" << endl;
            }

        } while (chemical < 0 || chemical > 10);

        Student newStudent(name, age, gender, math, physic, chemical);

        database.push_back(newStudent);

        cout<< "----------------" << endl;
            // Print the information of the newly added student

            cout << "ID: " << newStudent.getID() << endl;
            cout << "Name: " << newStudent.getName() << endl;
            cout << "Age: " << newStudent.getAge() << endl;
            cout << "Gender: " << (newStudent.getGender() == MALE ? "MALE" : "FEMALE") << endl;
            cout << "Math \t| Physic \t| Chemical \n";
            cout << newStudent.getMathScore() << "\t|" << newStudent.getPhysicScore() << "\t\t|" << newStudent.getChemicalScore() << endl;
            
            cout << "Avg Score: " << newStudent.getAverage() << endl;

            // Get and print the rank
            Rank rank = newStudent.getRank();
            cout << "Rank: ";
            switch (rank)
            {
            case GIOI:
                cout << "GIOI" << endl;
                break;
            case KHA:
                cout << "KHA" << endl;
                break;
            case TRUNG_BINH:
                cout << "TRUNG BINH" << endl;
                break;
            case YEU:
                cout << "YEU" << endl;
                break;
            default:
                cout << "Unknown" << endl;
                break;
            }

            cout << "-------------" << endl;
        cout << "1. Add new Student." << endl;
        cout << "0. Back." << endl;

        int choice;
        cout << "Please choose function :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            break; // Continue adding students
        case 0:
            return; // Return to the caller
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}

void deleteStudent(list<Student>& database)
{
    string nameToEdit;
    cout << "Enter the name student to be delete:";
    cin >> nameToEdit;

    bool found = false;
    cout << "---------------" << endl;
    int stt = 1; //

    cout << "STT\t| Name\t| ID\n";

    for (auto& student : database)
    {
        if (student.getName() == nameToEdit)
        {
            cout << stt << "\t|" << student.getName() << "\t|" << student.getID() << endl;
            stt++;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No student found with the name : " << nameToEdit << endl;
        cout << "---------------" << endl;

        return;
    }

    int idToDelete;

    cout << "Enter the student ID to be deleted: ";
    cin >> idToDelete;
    cout << "---------------" << endl;


    auto it = database.begin();
    while (it != database.end())
    {
        if (it->getID() == idToDelete)
        {

            // Erase the student from the list
            it = database.erase(it);
            cout << "Student with ID " << idToDelete << " has been deleted.\n";
            cout << "---------------" << endl;

            return; // Exit the function once the student is deleted
        }
        else
        {
            ++it;
        }
    }
    // If the loop completes without finding the student
    cout << "Student with ID " << idToDelete << " not found in the database.\n";
    cout << "---------------" << endl;

}


void editStudent(list<Student>& database)
{
    string nameToEdit;
    cout << "Enter the name student to be edit:";
    cin >> nameToEdit;

    bool found = false;
    cout << "---------------" << endl;
    int stt = 1; //

    cout << "STT\t| Name\t| ID\n";

    for (auto& student : database)
    {
        if (student.getName() == nameToEdit)
        {
            cout << stt << "\t|" << student.getName() << "\t|" << student.getID() << endl;
            stt++;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No student found with the name : " << nameToEdit << endl;
        return;
    }


    int idToEdit;
    cout << "Enter the student ID to be edit:";
    cin >> idToEdit;

    bool studentFound = false;
    for (auto& student : database)
    {
        if (student.getID() == idToEdit)
        {
            int choice;
            do
            {
                cout << "Choice option:\n";
                cout << "1. Edit name\n";
                cout << "2. Edit age\n";
                cout << "3. Edit gender\n";
                cout << "4. Edit math score\n";
                cout << "5. Edit physic score\n";
                cout << "6. Edit chemical score\n";
                cout << "0. Back\n";
                cout << "Your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                {   
                    string newName;
                    cout << "Enter the new name: ";
                    cin >> newName;
                    student.setName(newName);
                    cout << "Updated information successfully" << endl;
                    break;
                }
                case 2:
                {
                    int newAge;
                    cout << "Enter the new age: ";
                    cin >> newAge;
                    student.setAge(newAge);
                    cout << "Updated information successfully";

                    break;
                }
                case 3:
                {
                    int genderChoice;
                    cout << "Enter the new gender(0 - MALE / 1 - FEMALE) : ";
                    cin >> genderChoice;
                    Gender newGender = (genderChoice == 0) ? MALE : FEMALE;
                    student.setGender(newGender);
                    cout << "Updated information successfully";

                    break;
                }
                case 4:
                {
                    double newMath;
                    cout << "Enter the new math score: ";
                    cin >> newMath;
                    student.setMathScore(newMath);
                    cout << "Updated information successfully";

                    break;
                }
                case 5:
                {
                    double newPhysic;
                    cout << "Enter the new physics score: ";
                    cin >> newPhysic;
                    student.setPhysicScore(newPhysic);
                    cout << "Updated information successfully";

                    break;
                }
                case 6:
                {
                    double newChemical;
                    cout << "Enter the new chemistry score: ";
                    cin >> newChemical;
                    student.setChemicalScore(newChemical);
                    cout << "Updated information successfully";

                    break;
                }
                case 0:
                    break; // Return to the caller
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            } while (choice != 0);

            studentFound = true;
            break;
        }
    }

    if (!studentFound)
    {
        cout << "Student with ID " << idToEdit << " not found in the database." << endl;
    }
}
void searchStudent(list<Student> database)
{   
    int choice;
    cout << "Choose search criteria:" << endl;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by name" << endl;
    cout << "0. Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {   
        while (true)
        {

        int idToSearch;
        cout << "Enter the student ID to search: ";
        cin >> idToSearch;
        cout << "---------------" << endl;

        int stt = 1; //

        cout << "STT\t| ID\t\t| Name\t| Gender\t| Average \t| Rank\n ";

        bool found = false;
        for ( auto& student : database)
        {
            if (student.getID() == idToSearch)
            {
                cout << stt ;
                cout <<"\t|" << student.getID() ;
                cout <<"\t|" << student.getName();
               
                cout <<"\t|" << (student.getGender() == MALE ? "MALE" : "FEMALE");

                cout <<"\t\t|" <<  student.getAverage() ;

                Rank rank = student.getRank();
                switch (rank)
                {
                case GIOI:
                    cout << "\t|" << "GIOI" << endl;
                    break;
                case KHA:
                    cout << "\t|" << "KHA" << endl;
                    break;
                case TRUNG_BINH:
                    cout << "\t|" << "TRUNG BINH" << endl;
                    break;
                case YEU:
                    cout <<"\t|"<< "YEU" << endl;
                    break;
                default:
                    cout << "Unknown" << endl;
                    break;
                }

                
                stt++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Student with ID " << idToSearch << " not found in the database." << endl;
        }
       

        cout << "-------------" << endl;
        cout << "1. Search df Student." << endl;
        cout << "0. Back." << endl;

        int choice;
        cout << "Please choose function :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            break; // Continue adding students
        case 0:
            return; // Return to the caller
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }

        break;
    }
    case 2:
    {   
        while (true)
        {
            string nameToSearch;
            cout << "Enter the student name to search: ";
            cin >> nameToSearch;

            cout << "---------------" << endl;

            int stt = 1; //

            cout << "STT\t| ID\t\t| Name\t| Gender\t| Average\t| Rank\n ";

            bool found = false;
            for (auto& student : database)
            {
                if (student.getName() == nameToSearch)
                {
                    cout << stt;
                    cout << "\t|" << student.getID();
                    cout << "\t|" << student.getName();

                    cout << "\t|" << (student.getGender() == MALE ? "MALE" : "FEMALE");

                    cout << "\t\t|" << student.getAverage()<< "\t\t";

                    Rank rank = student.getRank();
                    switch (rank)
                    {
                    case GIOI:
                        cout << "GIOI" << endl;
                        break;
                    case KHA:
                        cout << "KHA" << endl;
                        break;
                    case TRUNG_BINH:
                        cout << "TRUNG BINH" << endl;
                        break;
                    case YEU:
                        cout << "YEU" << endl;
                        break;
                    default:
                        cout << "Unknown" << endl;
                        break;
                    }


                    stt++;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student with name " << nameToSearch << " not found in the database." << endl;
            }

            cout << "-------------" << endl;
            cout << "1. Search df Student." << endl;
            cout << "0. Back." << endl;

            int choice;
            cout << "Please choose function :";
            cin >> choice;
            switch (choice)
            {
            case 1:
                break; // Continue adding students
            case 0:
                return; // Return to the caller
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}


void arrangeStudent(list<Student>& database)
{
    cout << "arrange Student" << endl;
    cout << "--------------------" << endl;
    int choice;
    cout << "1. Arrange by name" << endl;
    cout << "2. Arrange by math score" << endl;
    cout << "3. Arrange by physics score" << endl;
    cout << "4. Arrange by chemistry score" << endl;
    cout << "5. Arrange by average score" << endl;
    cout << "0. Return" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        database.sort([](Student& a, Student& b) {
            return a.getName() > b.getName();
            });
        break;
    case 2:
        database.sort([](Student& a, Student& b) {
            return a.getMathScore() > b.getMathScore();
            });
        break;
    case 3:
        database.sort([](Student& a, Student& b) {
            return a.getPhysicScore() > b.getPhysicScore();
            });
        break;
    case 4:
        database.sort([](Student& a, Student& b) {
            return a.getChemicalScore() > b.getChemicalScore();
            });
        break;
    case 5:
        database.sort([]( Student& a,  Student& b) {
            return a.getAverage() > b.getAverage();
        });
        break;
    case 0:
        // Return to the caller
        return;
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    // Display the sorted list of students
    cout << "Students arranged:" << endl;
    // Print student information as desired

    cout << "STT\t| ID\t\t| Name\t| Gender\t| Math\t| Physics\t| Chemistry\t| Average\t| Rank\n";
    int stt = 1;
    for (auto& student : database) {
        cout << stt;
        cout << "\t|" << student.getID();
        cout << "\t|" << student.getName();
        cout << "\t|" << (student.getGender() == MALE ? "MALE" : "FEMALE");
        cout << "\t\t|" << student.getMathScore();
        cout << "\t|" << student.getPhysicScore();
        cout << "\t\t|" << student.getChemicalScore();

        cout << "\t\t|" << student.getAverage() << "\t\t|";

        Rank rank = student.getRank();
        switch (rank)
        {
        case GIOI:
            cout << "GIOI" << endl;
            break;
        case KHA:
            cout << "KHA" << endl;
            break;
        case TRUNG_BINH:
            cout << "TRUNG BINH" << endl;
            break;
        case YEU:
            cout << "YEU" << endl;
            break;
        default:
            cout << "Unknown" << endl;
            break;
        }


        stt++;
    }
}

void displayStudentDatabase(list<Student> database)
{
    {

        while (true)
        {
            cout << "STT\t| ID\t\t| Name\t| Gender\t| Math\t| Physics\t| Chemistry\t| Average\t| Rank\n";
            int stt = 1;
            for (auto& student : database) {
                cout << stt;
                cout << "\t|" << student.getID();
                cout << "\t|" << student.getName();
                cout << "\t|" << (student.getGender() == MALE ? "MALE" : "FEMALE");
                cout << "\t\t|" << student.getMathScore();
                cout << "\t|" << student.getPhysicScore();
                cout << "\t\t|" << student.getChemicalScore();

                cout << "\t\t|" << student.getAverage() << "\t\t|";

                Rank rank = student.getRank();
                switch (rank)
                {
                case GIOI:
                    cout  << "GIOI" << endl;
                    break;
                case KHA:
                    cout << "KHA" << endl;
                    break;
                case TRUNG_BINH:
                    cout << "TRUNG BINH" << endl;
                    break;
                case YEU:
                    cout << "YEU" << endl;
                    break;
                default:
                    cout << "Unknown" << endl;
                    break;
                }


                stt++;
            }
           
            
            cout << "-------------" << endl;
            cout << "0. Back." << endl;

            int choice;
            cout << "Please choose function :";
            cin >> choice;
            switch (choice)
            {
            case 0:
                return; // Return to the caller
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
}



void saveStudentDatabase(list<Student>& database)
{
    ofstream outFile("student_database.csv");
    if (outFile.is_open())
    {
        for ( auto& student : database)
        {
            outFile << student.getID() << " " << student.getName() << " " << student.getAge() << " ";
            outFile << static_cast<int>(student.getGender()) << " ";
            outFile << student.getMathScore() << " " << student.getPhysicScore() << " " << student.getChemicalScore() << std::endl;
        }
        outFile.close();
        std::cout << "save to file student_database.txt." << std::endl;
    }
    else
    {
        std::cout << "can't open file." << std::endl;
    }
}

