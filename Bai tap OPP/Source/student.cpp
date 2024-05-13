/*
Description: implements the methods of the Student class
*/

#include "student.hpp"

/* 
Function: setName
Description: Sets the name of the student
Input: A string representing the name of the student.
Output: None
 */

void Student::setName(string name)
{
    this->name = name;
}

/* 
Funtion: getName
Description: get the name of the student.
Input: None
Output: Returns a string representing the name of the student.
 */
string Student::getName() 
{
    return name;
}

void Student::setAge(int age)
{
    this->age = age;
}

int Student::getAge() 
{
    return age;
}

void Student::setGender(Gender gender)
{
    student_gender = gender;
}

Gender Student::getGender() 
{
    return student_gender;
}

void Student::setMathScore(double score)
{
    math_score = score;
}

double Student::getMathScore() 
{
    return math_score;
}

void Student::setPhysicScore(double score)
{
    physic_score = score;
}

double Student::getPhysicScore() 
{
    return physic_score;
}

void Student::setChemicalScore(double score)
{
    chemical_score = score;
}

double Student::getChemicalScore() 
{
    return chemical_score;
}

int Student::getID() 
{
    return id;
}


/*
Function: getAverage
Description: Calculates the average score of the student based on their scores in math, physics and chemistry
Input:None
Output: return (math_score + physic_score + chemical_score) / 3
*/

double Student::getAverage()
{
    return (math_score + physic_score + chemical_score) / 3;
}

/*
Function: getRank 
Description: Determines the rank of the sutudent based on their average score.
Input:None
Output: Return the rank of the student:
        - GIOI if average score >= 8.0
        - KHA if average score >= 6.5
        - TRUNG_BINH if average score >= 5.0
        - YEU otherwise
*/

Rank Student::getRank() 
{
    double average = getAverage();
    if (average >= 8.0){
        return GIOI;
    }
    else if (average >= 6.5){
       return KHA;
    }
    else if (average >= 5.0){
        return TRUNG_BINH;
    }
    else{
        return YEU;
    }
}
