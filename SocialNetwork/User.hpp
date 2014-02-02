#ifndef User_CPP
#define User_CPP

#include "User.h"
#include "Wall.hpp"

User::User()
{
	totalpokes = 0;
	sep = false;
}
User::User(string name, string pass, string school)//constructor, pass in 3 privates
{
    username = name;
    password = pass;
    university = school;
    totalpokes = 0;
    sep = false;
}

User::~User()//destructor
{

}

string User::getName() const
{
	return name;
}

void User::setName(string setname)
{
	name = setname;
}

bool User::getSeperate()
{
	return sep;
}

bool User::setSeperate(bool set)
{
	sep = set;
}

string User::getUsername() const//gets usernamae (getter)
{
    return username;
}
void User::setUsername(string user)//setter
{
    username = user;
}
string User::getPassword() const//getter for password
{
    return password;
}
void User::setPassword(string pass)//setter for password
{
    password = pass;
}
string User::getUniversity() const//getter for university
{
    return university;
}
void User::setUniversity(string college)//setter for university
{
    university = college;
}


void User::addOwnPost(string const name)//adds post to own wall
{
    setwall.addPost(name);
}

void User::addPoke(User* poker)
{
	pokes.push_back(poker);
}

void User::deletePoke(int const entry)
{
	pokes.erase(pokes.begin() + entry);
}

void User::addPostAutomatic(string const name, string const comment)
{
	setwall.automaticAdd(name, comment);
}

void User::deleteOwnPost()//deletes post to own wall
{
    setwall.removePost();
}

void User::printFunction(string const name)//prints as one line
{
    setwall.printPosts(name);
}

int User::getHash(int size)
{
	string tempName;
	tempName = getUsername();

	for(unsigned int i = 0; i < tempName.length(); i++)
	{
		size =  size + (int)tempName[i];
	}

	return size;
}

User::User(string n)
{
	int stringSize = n.size();
	int counter;
	string temporary;
	for(int i = 0; i < stringSize; i++)
	{
		temporary = temporary + n[i];
		if(n[i] == '\n')
		{
			counter++;
			if(counter%3 == 2)//1st line
			{
				//change the thing we are passing to username
				username = temporary;
				temporary = "";
			}
			else if(counter%3 == 1)//2nd line
			{
				password = temporary;
				temporary = "";
			}
			else
			{
				university = temporary;
				temporary = "";
			}
		}
	}
}

void User::editUser(string name)
{

	  cout << "Which of the following fields would you like to change?\n**"
			  "Note**\nYou are not allowed to change your username." << endl;
	  cout << "\n1)Password\n2)University\n3)Name" << endl;
	  cout << endl;
	  int changeField;
	  cin >> changeField;
	  cout << endl;
	  string golden;
	  string university;
	  while(changeField!=1 && changeField != 2 && changeField != 3)
	  {
		  cout << "Please enter a correct value." << endl;
		  cin >> changeField;
	  }

	  if(changeField == 1)
	  {
		  cout << "You chose to change your password." << endl;
		  cout << endl;
		  cout << "What would you like to change your new password to?" << endl;
		  string newPassword;
		  cin >> newPassword;
		  golden = newPassword;
		  cout << endl;
		  cout << "Please enter your new password again!" << endl;
		  string temp;
		  cin >> temp;
		  while (temp != golden)
		  {
			  cout << "Please enter your correct password." << endl;
			  cin >> temp;
		  }
		  cout << endl;
		  setPassword(golden);
		  cout << "You have successfully changed your password!" << endl;
  }

  else if(changeField == 2)
  {
	  cout << "Please enter your current university." << endl;
	  cout << endl;
	  string currentUniversity;
	  getline(cin, currentUniversity);
	  getline(cin,currentUniversity);
	  cout << endl;
	  university = currentUniversity;
	  setUniversity(university);
	  cout << "Welcome to " << currentUniversity << endl;
  }
  else if(changeField == 3)
  {
	  cout << "Your current name is " << name << endl;
	  cout << endl;
	  cout << "What would you like to change your name to?" << endl;
	  cout << endl;
	  string changeName;
	  cin >> changeName;
	  setName(changeName);
	  cout << "Hello! " << changeName << endl;
  }
}

void User::addPendingRequests(User* addUser)
{
	requests.push_back(addUser);
}

void User::addFriends(User* friendship)
{
	friends.push_back(friendship);
}

string User::returnRequest(int const name)
{
	return requests[name]->getUsername();
}

string User::returnFriend(int const name)
{
	return friends[name]->getUsername();
}

void User::deleteFriendRequests(int const name)
{
	requests.erase(requests.begin() + name);
}

void User::deleteFriend(const int myName) //iterates through until finds user that is going to be deleted
{
	friends.erase(friends.begin() + myName);
}

void User::printFriends()
{
	int iterator = 1;
	for(unsigned int i = 0; i < friends.size(); i++)
	{
		cout << iterator << ": You are friends with " << friends[i]->getUsername();
		cout << endl;
		iterator++;
	}
}

void User::printRequests()
{
	int iterator = 1;
	for(unsigned int i = 0; i < requests.size(); i++)
	{
		cout << iterator << "- " << requests[i]->getUsername();
		cout << endl;
		iterator++;
	}
}

void User::viewPokes()
{
	int iterator = 1;
	for(unsigned int i = 0; i < pokes.size(); i++)
	{
		cout << iterator << " - " << pokes[i]->getUsername() << " poked you." << endl;
		iterator++;
	}
}

int User::getnumberOfPokes()
{
	return totalpokes;
}

void User::setnumberOfPokes(int number)
{
	totalpokes = number;
}
#endif // User_CPP
