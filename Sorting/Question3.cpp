/*
 * Question3.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Shashank
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>

using namespace std;
/*
void quickSort(string *array, int a, int b);

int main()
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

		quickSort(array, 0, tempSize-1);

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
}
void quickSort(string *array, int a, int b)
{
	int left = a;
	int right = b;
	string mid = array[(a + b)/2];
	string swapElements;
	while(left <= right)
	{
		while(array[left].compare(mid)<0)
		{
			left++;
		}
		while(array[right].compare(mid)>0)
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
*/
