/*
 * HashTable.h
 *
 *  Created on: Dec 2, 2013
 *      Author: Shashank
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

template <class KeyType, class ValueType>
struct Node
{
	KeyType key;
	ValueType value;
	int initialSize;
};

template <class KeyType, class ValueType>
class Hashtable : private vector<Node<KeyType, ValueType> >
{
public:
	Hashtable();
	~Hashtable();
	void add (ValueType & tempvalue);
	void remove (ValueType * tempkey);
	ValueType * get (const KeyType & tempkey);
	bool contains (const KeyType & tempkey, int &number);
	int getSize();
	int getSizeOfVector(int vector);
	ValueType getOriginalVector(int vector);
	ValueType getWord(const KeyType & tempkey, string query);
	Hashtable (int initialSize);
	void addFood(string & value);
	void addCalorie(int & value);
	void outputGPA(ValueType *student);
	void outputName(ValueType *student);
	void printAll();
	void printName();
	void printAllFoods();
private:
	int currentSize;
	int hashSize;
	vector< vector<ValueType> > table;
};

//#include "HashTable.cpp"
#endif /* HASHTABLE_H_ */
