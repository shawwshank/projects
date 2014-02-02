/*
 * Student.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: Shashank
 */

#include "Student.h"

using namespace std;

Student::Student()
{
	// TODO Auto-generated constructor stub
	name = "";
	GPA = 0.00;
}

Student::~Student()
{
	// TODO Auto-generated destructor stub
}

string Student::getName() const
{
	return name;
}

void Student::setName(string key)
{
	name = key;
}

double Student::getGPA() const
{
	return GPA;
}

void Student::setGPA(double temp)
{
	GPA = temp;
}

int Student::getHash()
{
	int value;
	value = 0;
	string tempName;
	tempName = getName();
	//cout << "hello";
	for(unsigned int i = 0; i < tempName.length(); i++)
	{
		value =  value + (int)tempName[i];
	}

	return value;
}
