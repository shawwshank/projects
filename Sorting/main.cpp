/*
 * main.cpp
 *
 *  Created on: Nov 20, 2013
 *      Author: Shashank
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>


using namespace std;

void quickSortString(string *array, int a, int b);
void quickSort(int *array, int left, int right);
void binarySearch(int *array, int start, int end, int value, int index);

int main()
{
	bool repeat;
	repeat = true;
	int choice;
while(repeat)
{
	cout << "Do you want to:\n"
			"1)Sort using strings\n"
			"2)Sort using integers\n"
			"3) Quit" << endl;
	cin >> choice;
	while(choice != 1 && choice != 2 && choice != 3)
	{
		cout << "Enter valid choice" << endl;
		cin >> choice;
	}
	if(choice == 1)
	{
		string line;
		ifstream file("sortString.txt");
		if(file.is_open())
		{
			string getSizeof;
			int tempSize;
			getline(file,getSizeof,'\n');
			tempSize = atoi(getSizeof.c_str());
			string array[tempSize];
			string goingToSort;
			for(int i = 0; i < tempSize; i++)
			{
				getline(file, goingToSort, '\n');
				array[i] = goingToSort;
			}
			//run quicksort based on alphabetical order

			quickSortString(array, 0, tempSize-1);

			//cout << endl;
			for(int i = 0; i < tempSize; i++)
			{
				//cout << array[i] << " ";
			}
			string tempElement = array[0];
			string first;
			int counter = 1;
			int diffElements = 1;
			int maximum = 0;
			for(int i = 1; i < tempSize; i++)
			{
				if(array[i] == tempElement)
				{
					counter = counter + 1;
					if(counter >= maximum)
					{
						maximum = counter;
						first = tempElement;
					}
				}
				if(array[i] != tempElement)
				{
					tempElement = array[i];
					counter = 1;
					diffElements++;
				}
			}
			cout << "Different elements: " << diffElements << endl;
			cout << endl;
			//account for ties
			int tempcounter = 1;
			string temp;
			string tieElement = array[0];
			for(int k = 1; k < tempSize; k++)
			{
				if(array[k] == tieElement)
				{
					tempcounter++;
					if(tempcounter == maximum)
					{
						temp = tieElement;
						cout << "The element " << temp << " appears a maximum " << maximum << " number of times" << endl;
					}
				}
				else
				{
					tieElement = array[k];
					tempcounter = 1;
				}
			}
		}
		cout << endl;
		cout << "Go Back to menu?(y/n)" << endl;
		string repeatMenu;
		cin >> repeatMenu;
		if(repeatMenu == "y" || repeatMenu == "Y")
		{
			repeat = true;
		}
		else
		{
			repeat = false;
			cout << "See you later!";
			break;
		}
	}
	else if(choice == 2)
	{
		string line;
		ifstream file("sortInts.txt");
		if(file.is_open())
		{
			cout << endl;
			string getSizeof;
			getline(file,getSizeof,',');
			cout << "Number of elements: "<< getSizeof << endl;
			string shouldAddupto;
			getline(file,shouldAddupto, '\n');
			cout << "Should add up to: "<< shouldAddupto << endl;
			int tempSize;
			tempSize = atoi(getSizeof.c_str());
			int sum;
			sum = atoi(shouldAddupto.c_str());
			int *array = new int[tempSize];
			string goingToSort;
			int insertIntoArray;
			for(int i = 0; i < tempSize; i++)
			{
				getline(file, goingToSort, '\n');
				insertIntoArray = atoi(goingToSort.c_str());
				array[i] = insertIntoArray;
			}

			//now we sort it
			quickSort(array, 0, tempSize-1);

			//outputting the original array
			cout << endl;
			cout << "Outputting first ten integers: " << endl;
			for(int i = 0; i < 10; i++)
			{
				cout << array[i] << endl;
			}
			//cout << endl;
			cout << "--------------";
			cout << endl;
			cout << "Outputting last ten integers:" << endl;
			for(int i = tempSize-10; i < tempSize; i++)
			{
				cout << array[i] << endl;
			}
			//cout << endl;
			cout << "-----" << endl;
			int findSum;
			int tempNumber;
			for(int i = 0; i < tempSize; i++)
			{
				findSum = sum - array[i];
				tempNumber = array[i];
				binarySearch(array, 0, tempSize-1, findSum, tempNumber);
			}
			delete array;
		}
		file.close();
		cout << endl;
		cout << "Go Back to menu?(y/n)" << endl;
		string repeatMenu;
		cin >> repeatMenu;
		if(repeatMenu == "y" || repeatMenu == "Y")
		{
			repeat = true;
		}
		else
		{
			cout << "See you later!";
			break;
		}
	}
	else if(choice == 3)
	{
		cout << "See you later!";
		repeat = false;
		break;
	}
}

}

void quickSortString(string *array, int a, int b)
{
	int left = a;
	int right = b;
	string mid = array[(a + b)/2];
	string swapElements;
	while(left <= right)
	{
		while(array[left].compare(mid)<0) //left string is greater than right
		{
			left++;
		}
		while(array[right].compare(mid)>0) //right string is greater than left
		{
			right--;
		}
		if( left <= right)
		{
			swapElements = array[left];
			array[left] = array[right];
			array[right] = swapElements;
			left++;
			right--;
		}
	}

	if(a < right)
	{
		quickSortString(array,a, right);
	}
	if(left < b)
	{
		quickSortString(array, left, b);
	}
}
void binarySearch(int *array, int start, int end, int value, int index)
{
	bool found = false;
	int mid = (start + end)/2;
	while(start < end && !found)
	{
		if(array[mid] == value)
		{
			cout << "A Pair exists!" << " ";
			cout << "(" << value << "," << index << ")" << endl;
			cout << value << " + " << index << " = " << value + index;
			found = true;
		}
		else if(array[mid] < value)
		{
			binarySearch(array, mid+1, end, value, index);
			found = true;
		}
		else
		{
			binarySearch(array, start, mid-1, value, index);
			found = true;
			cout << "";
		}
	}
}
void quickSort(int *array, int a, int b)
{
	int left = a;
	int right = b;
	int mid = array[(a + b)/2];
	int swapElements;
	while(left <= right)
	{
		while(array[left] < mid)
		{
			left++;
		}
		while(array[right] > mid)
		{
			right--;
		}
		if( left <= right)
		{
			swapElements = array[left];
			array[left] = array[right];
			array[right] = swapElements;
			left++;
			right--;
		}
	}
	if(a < right)
	{
		quickSort(array,a, right);
	}
	if(left < b)
	{
		quickSort(array, left, b);
	}
}
