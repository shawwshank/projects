/*
 * HashTable.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: Shashank
 */

#include "HashTable.h"

template <class KeyType, class ValueType>
Hashtable<KeyType, ValueType>::Hashtable()
{
	hashSize = 0;
	currentSize = 0;
}

template <class KeyType, class ValueType>
Hashtable<KeyType, ValueType>::Hashtable (int initialSize)
{
	currentSize = 0;
	hashSize = initialSize;
	table.resize(initialSize);
}

template <class KeyType, class ValueType>
Hashtable<KeyType, ValueType>::~Hashtable()
{
	// TODO Auto-generated destructor stub
}

//gets size of hash table
template <class KeyType, class ValueType>
int Hashtable<KeyType, ValueType>::getSize()
{
	return table.size();
}

//gets size of that specific bucket
template <class KeyType, class ValueType>
int Hashtable<KeyType, ValueType>::getSizeOfVector(int vector)
{
	return table[vector].size();
}

//returns the bucket
template <class KeyType, class ValueType>
ValueType Hashtable<KeyType, ValueType>::getOriginalVector(int vector)
{
	return table[vector][0];
}

//adds a key/value to the hash table
//calls gethash function, which i then mod to the tablesize
//add to vector
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>:: add(ValueType & tempvalue) //adds key and value to hashtable
{
	int value;
	value = tempvalue.getHash();
	int resizeValue;
	resizeValue = value % table.size();
	//cout << value;
	table[resizeValue].push_back(tempvalue);
	//cout << "Works!" << endl;
	currentSize++;
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>:: addFood(string & value)
{
	int index = 0;
	for(unsigned int i = 0; i < value.length(); i++)
	{
		index =  index + (int)value[i];
	}
	int tempValue;
	tempValue = index % table.size();

	table[tempValue].push_back(value);
	//cout << "added!" << endl;
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>:: addCalorie(int & value)
{
	int index = 0;
	index =  index + value;
	int tempValue;
	tempValue = index % table.size();

	table[tempValue].push_back(value);
}

//simple print function that prints name and gpa
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::printAll()
{
	for(unsigned int i = 0; i<table.size(); i++)
	{
		for(unsigned int j = 0; j < table[i].size(); j++)
		{
			cout << "Student's name is: " << table[i][j].getName();
			cout << endl;
			cout << "Student's GPA is " << table[i][j].getGPA();
			cout << endl;
		}
	}
}

//just prints name for when i ask which they want to get
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::printName()
{
	for(unsigned int i = 0; i<table.size(); i++)
	{
		for(unsigned int j = 0; j < table[i].size(); j++)
		{
			cout << "Student's name is: " << table[i][j].getName();
			cout << endl;
		}
	}
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::printAllFoods()
{
	for(unsigned int i = 0; i<table.size(); i++)
	{
		for(unsigned int j = 0; j < table[i].size(); j++)
		{
			cout << table[i][j] << " ";
		}
		//cout << endl;
	}
}

//removes a record with the name that we pass in from the hash table
//basically everything to the right shifts over one to the left
//removes that vector
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::remove(ValueType * tempkey)
{
	if(tempkey == NULL)
	{
		cout << "There is no student record with this name." << endl;
		return;
	}
	int position;
	position = tempkey->getHash();
	unsigned int temp = 0;
	unsigned int tableSize = table[position].size();
	while(&table[position][temp] != tempkey && temp < tableSize)
	{
		temp++;
	}
	for(unsigned int j = temp; j < table[position].size() - 1; j++)
	{

		table[position][j] = table[position][j+1];
	}
	table[position].pop_back();

}

//outputs the gpa when i ask for the get function
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::outputGPA(ValueType *student)
{
	cout << "Name: " << student->getName();
	cout << endl;
	cout << "GPA: " << student->getGPA();
	cout << endl;
}

//outputs name when i ask for get function
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::outputName(ValueType *student)
{
	cout << "Name: " << student->getName();
	cout << endl;
}

//get function, sets name from the parameter
//goes through the hash table, if the name is the same, then
//it outputs that value
template <class KeyType, class ValueType>
ValueType * Hashtable<KeyType, ValueType>::get(const KeyType & tempkey)
{
	ValueType tempRecord;
	tempRecord.setName(tempkey);
	int index;
	index = tempRecord.getHash();
	for(unsigned int i = 0; i < table[index].size(); i++)
	{
		if(table[index][i].getName() == tempkey)
		{
			return & table[index][i];
		}
	}
	return NULL;
}


template <class KeyType, class ValueType>
ValueType Hashtable<KeyType, ValueType>:: getWord(const KeyType &tempkey, string query)
{
	ValueType tempRecord;
	int index = 0;

	for(unsigned int i = 0; i < query.length(); i++)
	{
		index += (int)query[i];
	}

	int tempValue = index % table.size();

	for(unsigned int i = 0; i < table[tempValue].size(); i++)
	{
		if(table[tempValue][i] == query)
		{
			return table[tempValue][i];
		}
	}
	return NULL;
}

template <class KeyType, class ValueType>
bool Hashtable<KeyType, ValueType>::contains(const KeyType & tempkey, int &number)
{
	for(unsigned int i = 0; i < table[number].size(); i++)
	{
		if(table[number][i] == tempkey)
		{
			return & table[number][i];
		}
	}
	return NULL;
}


