#ifndef USERLIST_CPP
#define USERLIST_CPP

#include "UserList.h"
#include "User.hpp"
#include <iterator>
#include <string>
#include <queue>
using namespace std;


UserList::UserList()//constructor
{

}

UserList::~UserList()//destructor
{
    //dtor
}
void UserList::addUser(User addtolist)//adds a user to the userlist database.
{
	users.add(addtolist);
}

void UserList::deleteUser()//deletes a user from the userlist database
{
	string userDel;
	cout << "Enter the username of the person you would like to delete." << endl;
	cin >> userDel;
	users.remove(userDel);
}

void UserList::writeFile()//writes all user to file
{

	/*ofstream file;
	file.open("userlist.txt");
	string writingInfo = "";
	string writingPosts = "";
	string writingComments = "";
	string username;
	string password;
	string university;
	string time;
	string newUser = "NEWUSER";
	string finalPost;
	string addMarkerAfterInfo = "-";
		if(file.is_open())
		{
			for(unsigned int i = 0; i < users.size(); i++)
				{
					username = user[i].getUsername();
					password = user[i].getPassword();
					university = user[i].getUniversity();
					writingInfo = username + '\n' + password + '\n' + university + '\n' + addMarkerAfterInfo;
					writingPosts = user[i].setwall.writeIntoString();
					//writingComments = user[i].setwall.init.writeCommentIntoString();
					finalPost = newUser + '\n' + writingInfo + '\n' + writingPosts;// + '\n' + writingComments;
					file << finalPost;
				}
		}
	file.close();*/
}
void UserList::readFile()//reads from file and outputs
{/*
	ifstream file;
	file.open("userlist.txt");
	//counts how many lines in file
	string tempVar;
	User USER;
	User User1;
	Wall WALL;
	bool repeat;
	if(file.is_open())
	{
		while(repeat == false)
		{
			getline(file,tempVar);
			getline(file, tempVar);
			cout << "username: " << tempVar << endl;
			USER.setUsername(tempVar);
			getline(file, tempVar, '\n');
			cout << "password: " << tempVar << endl;
			USER.setPassword(tempVar);
			getline(file, tempVar, '\n');
			cout << "univ: " << tempVar << endl;
			USER.setUniversity(tempVar);
			string add = "";
			while(!file.eof())
			{
				//add posts
				if(getline(file,tempVar, '\n') != "---")
				{
					//getline(file, tempVar);
					add += tempVar;
					cout << "comment: " << tempVar << endl;
					getline(file,tempVar);
					cout << "author: " << tempVar << endl;
					getline(file,tempVar);
					cout << "date: " << tempVar << endl;
					add += tempVar;
					repeat = true;
				}
				//once it hits ...
				if(tempVar == "---")
				{
					cout << "hello";
					repeat = false;
				}
				else
					repeat = true;
			}
	  }
	}*/
}


  void UserList::printAllUsers()
  {

	  users.printAll();
  }


User *UserList::searchForUser(const string &name)

{

	return users.get(name);
}

bool UserList::checkIfSame(string username)
{
	bool exists;

	exists = users.contains(username);

	return exists;
}


int UserList::seperation(User* x, int size, string findName)
{
	bool visited[size];
	int counter = 0;
	int distance = 1;
	bool set = false;

	if(findName == x->getUsername())
	{
		users.setFalse();
		return 0;
	}

	queue<User*> q;
	q.push(x);
	while(!q.empty())
	{
		User* v = q.front();

		q.pop();
		for(unsigned int i = 0; i < v->friends.size(); i++)
		{
			User* w = v->friends[i];

			bool exists = false;
			string tempUsername;
			tempUsername = w->getUsername();
			for(int k = 0; k < size; k++)
			{
				if(w->getSeperate() == true)//already been visited, skip it
				{
					break;
				}
			}
			if(w->getSeperate() == false)//hasn't been visited yet, increase counter every new
			{
				counter++;
				bool settrue = true;
				w->setSeperate(settrue);
				string names;
				names = w->getUsername();
				q.push(w);
			}
			if(findName == tempUsername)
			{
				users.setFalse();
				return distance;
			}
		}
		distance++;
	}
}

void UserList::roja(string const &query)
{

	for(int i = 0; i < users.getSize(); i++)
	{
		if(users.exists(i) == true)
		{
			string stringContains;
			stringContains = users.getUsername(i);
			string add = "";
			if(stringContains.find(query) != string::npos)
			{
				//return that username
				cout << add + stringContains + " " << endl;
				//i++;
			}
			else
			{

			}
		}
		else
		{
			//i++;
		}
	}
}

#endif // USERLIST_CPP
