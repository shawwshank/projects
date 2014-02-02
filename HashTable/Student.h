/*
 * Student.h
 *
 *  Created on: Dec 2, 2013
 *      Author: Shashank
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
	Student();
	~Student();
	string getName() const;
	void setName(string key);
	double getGPA() const;
	void setGPA(double temp);
	int getHash();
private:
	string name;
	double GPA;
};

#endif /* STUDENT_H_ */
