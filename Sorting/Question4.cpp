/*
 * Question4.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: Shashank
 */
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;
/*
void quickSort(int *array, int left, int right);
void binarySearch(int *array, int start, int end, int value, int index);

int main()
{
	string line;
	ifstream file("sortInts.txt");
	if(file.is_open())
	{
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
		cout << "Original Array: " << endl;
		for(int i = 0; i < tempSize; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
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

*/
//sort
//each number corresponds to its own index in another array(goes through for loop once)
//once adds in that array, sets that array to true
//if true, then it exists
//go through each index in array, and if n-1 exists, then a pair exists

//for loop, binary search for sum - array[i], if it exists, then cout the pair
//if not then it doesn't exist
