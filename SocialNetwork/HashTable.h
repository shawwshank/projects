/*
 * HashTable.h
 *
 *  Created on: Dec 10, 2013
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
class Hashtable
{
public:
	Hashtable();
	~Hashtable();
	void add (ValueType & tempvalue);
	void remove (const KeyType & tempkey);
	ValueType * get (const KeyType & tempkey);
	bool exists(int index);
	bool contains (string name);
	void setFalse();
	int getSize();
	int getSizeOfVector(int vector);
	string getUsername(int index);
	int getHash(int value);
	void printAll();

private:
	int currentSize;
	int hashSize;
	vector< vector<ValueType> > table;
	vector< vector<ValueType> > pokes;
};



#endif /* HASHTABLE_H_ */
