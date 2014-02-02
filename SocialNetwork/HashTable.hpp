/*
 * HashTable.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: Shashank
 */

#include "HashTable.h"

template <class KeyType, class ValueType>
Hashtable<KeyType, ValueType>::Hashtable()
{
	table.resize(10000);
	currentSize = 0;
	hashSize = 0;
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

template <class KeyType, class ValueType>
string Hashtable<KeyType, ValueType>::getUsername(int index)
{
	return table[index][0].getUsername();
}

//gets size of that specific bucket
template <class KeyType, class ValueType>
int Hashtable<KeyType, ValueType>::getSizeOfVector(int vector)
{
	return table[vector].size();
}


//adds a key/value to the hash table
//calls gethash function, which i then mod to the tablesize
//add to vector
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>:: add(ValueType & tempvalue) //adds key and value to hashtable
{
	int value;
	value = tempvalue.getHash(table.size());
	int index;
	index = value % table.size();
	//cout << "location " << index;
	//cout << value;
	table[index].push_back(tempvalue);
	//cout << "Works!" << endl;
	currentSize++;
}

template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>:: setFalse()
{
	for(int i = 0; i < table.size(); i++)
	{
		for(int j = 0; j < table[i].size(); j++)
		{
			if(table[i].size() > 0)
			{

				table[i][0].setSeperate(false);
			}
		}
	}
}
//simple print function that prints name and gpa
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::printAll()
{
	for(unsigned int i = 0; i<table.size(); i++)
	{
		for(unsigned int j = 0; j < table[i].size(); j++)
		{
			cout << "Name: " << table[i][j].getName() << ", ";
			cout << "Username " << table[i][j].getUsername();
			cout << endl;
		}
	}
}

template <class KeyType, class ValueType>
bool Hashtable<KeyType, ValueType>::exists(int index)
{
	bool exists;
	if(table[index].size() > 0)
	{
		exists = true;
	}
	else
	{
		exists = false;
	}
	return exists;
}

//removes a record with the name that we pass in from the hash table
//basically everything to the right shifts over one to the left
//removes that vector
template <class KeyType, class ValueType>
void Hashtable<KeyType, ValueType>::remove(const KeyType & tempkey)
{

	int position = 0;
	for(unsigned int i = 0; i < tempkey.length(); i++)
	{
		position = position + (int)tempkey[i];
	}
	int index;
	index = position % table.size();
	unsigned int temp = 0;
	string tableName = table[index][0].getUsername();
	while(tableName != tempkey && temp < table[index].size())
	{
		temp++;
	}
	for(unsigned int j = temp; j < table[index].size() - 1; j++)
	{

		table[index][j] = table[index][j+1];
	}
	table[index].pop_back();

}


//get function, sets name from the parameter
//goes through the hash table, if the name is the same, then
//it outputs that value
template <class KeyType, class ValueType>
ValueType * Hashtable<KeyType, ValueType>::get(const KeyType & tempkey)
{
	int index = 0;
	string name;
	name = tempkey;
	for(unsigned int i = 0; i < name.length(); i++)
	{
		index = index + (int)name[i];
	}
	int sum;
	sum = index % table.size();
	for(unsigned int i = 0; i < table[sum].size(); i++)
	{
		if(table[sum].size() > 0)
		{
			if(table[sum][0].getUsername() == name)
			{
				return &table[sum][0];
			}
		}
	}
}


template <class KeyType, class ValueType>
bool Hashtable<KeyType, ValueType>::contains(string name)
{
	bool exists;
	int number = 0;
	for(int i = 0; i < name.length(); i++)
	{
		number = number + (int)name[i];
	}

	int value;
	value = number % table.size();

	if(table[value].size() == 0)
	{
		exists = false;
		return exists;
	}
	else
	{
		exists = true;
		return exists;
	}
}

template class Hashtable<string, User>;

