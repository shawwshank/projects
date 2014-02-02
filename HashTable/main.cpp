/*
 * main.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: Shashank
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "HashTable.hpp"
#include "Student.h"

using namespace std;

int main()
{
	int mainChoice;
	bool mainRepeat = true;
	while(mainRepeat == true)
	{
		cout << "Welcome, which of the following do you want to do? (Enter 1-5)\n"
				"1)Student Directory\n"
				"2)Potluck Dinner\n"
				"3)Calories\n"
				"4)Google\n"
				"5)Quit" << endl;
		cin >> mainChoice;
		while(mainChoice != 1 && mainChoice != 2 && mainChoice != 3 && mainChoice != 4 && mainChoice !=5)
		{
			cout << "Please enter a valid choice." << endl;
			cin >> mainChoice;
		}

		if(mainChoice == 1)
		{
			Hashtable<string, Student> hash(1000);
			Student student;
			Student tempstudent;
			string name;
			double gpa;
			bool repeat = true;
			while(repeat)
			{
				cout << "Welcome! Which of the following do you want to do?(Enter 1-4)\n"
				"1)Add a student\n"
				"2)Remove a student\n"
				"3)Find a certain student\n"
				"4)Quit\n";

				int choice;
				cin >> choice;

				while(choice != 1 && choice != 2 && choice!= 3 && choice !=4)
				{
					cout << "Please enter a valid choice." << endl;
					cin >> choice;
				}

				if(choice == 1)
				{
					cout << "Please enter the student's name" << endl;
					cin >> name;
					cout << "Enter the GPA" << endl;
					cin >> gpa;
					student.setName(name);
					student.setGPA(gpa);
					hash.add(student);

					cout << "continue? (Y/N)" << endl;
					string loop;
					cin >> loop;
					if(loop == "y" || loop == "Y")
					{
						repeat = true;
					}
					else
					{
						repeat = false;
						break;
					}
				}
				else if(choice == 2)
				{
					hash.printName();
					cout << "What is the name of the student you want to remove?" << endl;
					string removeName;
					cin >> removeName;
					hash.remove(hash.get(removeName));
					hash.printAll();
					cout << "continue? (Y/N)" << endl;
					char loop;
					cin >> loop;
					if(loop == 'y' || loop == 'Y')
					{
						repeat = true;
					}
					else
					{
						repeat = false;
						break;
					}
				}
				else if(choice == 3)
				{
					hash.printName();
					cout << "What is the name of the student you want to look up?" << endl;
					string lookUp;
					cin >> lookUp;
					hash.outputGPA(hash.get(lookUp));

					cout << "continue? (Y/N)" << endl;
					char loop;
					cin >> loop;
					if(loop == 'y' || loop == 'Y')
					{
						repeat = true;
					}
					else
					{
						repeat = false;
						break;
					}
				}
				else if(choice == 4)
				{
					cout << "Bye!" << endl;
					repeat = false;
					mainRepeat = true;
					break;
				}
				if(repeat == false)
				{
					mainRepeat = true;
					break;
				}
			}

			cout << endl;
			cout << "Go Back to menu?(y/n)" << endl;
			string repeatMenu;
			cin >> repeatMenu;
			if(repeatMenu == "y" || repeatMenu == "Y")
			{
				mainRepeat = true;
			}
			else
			{
				cout << "See you later!";
				break;
			}
		}
		else if(mainChoice == 2)
		{
			cout << "Potluck dinner question. Press any key to continue." << endl;
			char continued;
			cin >> continued;
			string line;
			ifstream file;
			file.open("dinner.txt");
			string totalNumberStr;
			getline(file, totalNumberStr);
			int totalNumber;
			totalNumber = atoi(totalNumberStr.c_str());
			cout << "Total number of items: " << totalNumber << endl;
			string *array;
			array = new string[totalNumber];

			for(int i = 0; i < totalNumber; i++)
			{
				getline(file, line);
				array[i] = line;
			}

			Hashtable<string, string> dinner(totalNumber);
			string temp;
			for(int i = 0; i < totalNumber; i++)
			{
				temp = array[i];

				dinner.addFood(temp);
			}

			int *sizeArray;

			int sizeOf = dinner.getSize();
			cout << endl;
			cout << "Size of vector " << sizeOf << endl;
			sizeArray = new int[sizeOf];

			for(int i = 0; i < sizeOf; i++)
			{
				sizeArray[i] = 1;
			}
			for(int i = 0; i < sizeOf; i++)
			{
				sizeArray[i] = dinner.getSizeOfVector(i);
			}

			string calories;
			for(int i = 0; i < sizeOf; i++)
			{
				if(sizeArray[i] != 0)
				{
					calories = dinner.getOriginalVector(i);
				}
			}

			/*for(int i = 0; i < sizeOf; i++)
			{
				cout << sizeArray[i] << " ";
			}*/
			int maximum = 0;
			for(int i = 0; i < sizeOf; i++)
			{
				if(sizeArray[i] > maximum)
				{
					maximum = sizeArray[i];
				}
			}

			string ifEqual;
			for(int i = 0; i< sizeOf; i++)
			{
				if(sizeArray[i] == maximum)
				{
					ifEqual = dinner.getOriginalVector(i);
					cout << "Maximum: " << ifEqual << ", Size: " << sizeArray[i] << " ";
				}
			}

			cout << endl;
			cout << "Go Back to menu?(y/n)" << endl;
			string repeatMenu;
			cin >> repeatMenu;
			if(repeatMenu == "y" || repeatMenu == "Y")
			{
				mainRepeat = true;
			}
			else
			{
				cout << "See you later!";
				break;
			}
		}
		else if(mainChoice == 3)
		{
			string turkeys;
			string sides;
			string calories;
			ifstream file;
			file.open("calories.txt");
			getline(file,turkeys,',');
			int numOfTurkeys;
			int numSides;
			int numCalories;
			numOfTurkeys = atoi(turkeys.c_str());
			getline(file, sides, ',');
			numSides = atoi(sides.c_str());
			getline(file, calories, '\n');
			numCalories = atoi(calories.c_str());
			cout << "Number of turkeys: " << numOfTurkeys << endl;
			cout << "Number of sides: " << numSides << endl;
			cout << "Calories: " << numCalories << endl;
			int sizeOfArray;
			sizeOfArray = numOfTurkeys + numSides;
			cout << "Size of Array: " << sizeOfArray << endl;
			int *array;
			array = new int[sizeOfArray];
			string line;
			int number;

			Hashtable<int, int> thanks(10000);
			for(int i = 0; i < numOfTurkeys; i++)
			{
				getline(file, line,'\n');
				number = atoi(line.c_str());
				array[i] = number;
				thanks.addCalorie(array[i]);
			}

			for(int i = 0; i < numOfTurkeys; i++)
			{
				cout << array[i] << " ";
			}

			for(int i = numOfTurkeys; i < sizeOfArray; i++)
			{
				getline(file, line, '\n');
				number = atoi(line.c_str());
				array[i] = number;
				cout << array[i] << " ";
			}

			cout << endl;
			for(int i = numOfTurkeys; i < sizeOfArray; i++)
			{
				int finalNum;
				finalNum = numCalories - array[i];
				//cout << finalNum << " ";
				if(thanks.contains(finalNum,finalNum) == true)
				{
					cout << array[i] << "+" << finalNum << "=" << numCalories << endl;
				}
			}

			cout << "Go Back to menu?(y/n)" << endl;
			string repeatMenu;
			cin >> repeatMenu;
			if(repeatMenu == "y" || repeatMenu == "Y")
			{
				mainRepeat = true;
			}
			else
			{
				cout << "See you later!";
				break;
			}
		}
		else if(mainChoice == 4)
		{
			string stringLines;
			ifstream file;
			file.open("google.txt");
			getline(file, stringLines, '\n');
			int numOfLines;
			numOfLines = atoi(stringLines.c_str());

			string lineByLine;
			string *arrayOfLines;
			arrayOfLines = new string[numOfLines];

			for(int i = 0; i < numOfLines; i++)
			{
				getline(file, lineByLine, '\n');
				arrayOfLines[i] = lineByLine;
			}

			int counter = 1;
			for(int i = 0; i < numOfLines; i++)
			{
				cout << "Line " << counter << ": " << arrayOfLines[i] << endl;
				counter++;
			}
			file.close();

			file.open("google.txt");
			getline(file, stringLines, '\n');

			Hashtable<string, string> google(200000);
			string words;
			while(!file.eof())
			{
				getline(file, words, ' ');
				google.addFood(words);
			}
			cout << endl;
			google.printAllFoods();

			cout << endl;
			cout << endl;
			cout << "Which word would you like to search for?" << endl;
			string query;
			cin >> query;
			cout << "You searched for " << query << "."<< endl;
			cout << endl;
			string getWord;
			getWord = google.getWord(query, query);

			for(int i = 0; i < numOfLines; i++)
			{
				if(arrayOfLines[i].find(getWord) != string::npos)
				{
					cout << arrayOfLines[i] << endl;
				}
			}

			cout << endl;
			cout << "Go Back to menu?(y/n)" << endl;
			string repeatMenu;
			cin >> repeatMenu;
			if(repeatMenu == "y" || repeatMenu == "Y")
			{
				mainRepeat = true;
			}
			else
			{
				cout << "See you later!";
				break;
			}
		}
		else if(mainChoice == 5)
		{
			cout << "Goodbye!" << endl;
			mainRepeat = false;
		}
	}
}
