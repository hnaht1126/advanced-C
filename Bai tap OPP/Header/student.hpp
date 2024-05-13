/*
Description: The class sutdent represents a student
with essential attributes and functionality for managing student data
and performance assessment
*/

#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_

#include <string>

using namespace std;

typedef enum Gender
{
	MALE,
	FEMALE
} Gender;

typedef enum Rank
{
	GIOI,
	KHA, 
	TRUNG_BINH,
	YEU
} Rank;

class Student
{
private:
	int id;
	string name;
	int age;
	Gender student_gender;
	double math_score;
	double physic_score;
	double chemical_score;

public:
	Student(string name, int age, Gender gender, double math, double physic, double chemical) : 
	name(name), age(age), student_gender(gender), math_score(math), physic_score(physic), chemical_score(chemical){
		static int ID = 20119281;
		id = ID;
		ID++;
	};

	void setName(string name);
	string getName();

	void setAge(int age);
	int getAge();

	void setGender(Gender gender);
    Gender getGender();

    void setMathScore(double score);
    double getMathScore();

    void setPhysicScore(double score);
    double getPhysicScore();

    void setChemicalScore(double score);
    double getChemicalScore();
	

	int getID();

	double getAverage();
	Rank getRank();

};

#endif 