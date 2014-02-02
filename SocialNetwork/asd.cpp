#include <iostream>
#include <string>
#include "Wall.hpp"
#include "WallPost.hpp"
#include "User.hpp"
#include "UserList.hpp"
#include "WallpostComment.hpp"
#include <cstdlib>

using namespace std;

void menu(int choice, bool &goBackToFirstMenu, UserList &dataList);
void checkUsername(UserList &dataList);
char generatingRandom();
User* searchUser(string loginUsername, bool &successfulSearch, UserList &dataList);
void secondMenu(User &person, UserList &dataList);

int main()
{
	UserList dataList;
	Wall userWall;
	userWall.printAll();
	//dataList.readFile();
	bool goBackToFirstMenu = true;
	int choice;

	while(goBackToFirstMenu == true)
	{
		cout << "Look at the menu below and\nenter the corresponding number." << endl;
		cout << "1)Log in as a user.\n2)Create a new user\n3)Print Users\n4)Delete User" << endl << endl;

		cin >> choice;

		menu(choice, goBackToFirstMenu, dataList);

		cout << "Would you like to go back to the main menu? (Y/N)" << endl;

		string goBackToMainMenu;
		cin >> goBackToMainMenu;
		if(goBackToMainMenu == "Y" || goBackToMainMenu == "y")
		{
			goBackToFirstMenu = true;
			//menu(choice, goBackToFirstMenu, dataList);
		}
		else if(goBackToMainMenu == "N" || goBackToMainMenu == "n")
		{
			cout << "Goodbye! Hope you have a good one!" << endl;
			goBackToFirstMenu = false;
		}
		else
		{
			cout << "Enter a valid choice" << endl;
			cin >> goBackToMainMenu;
		}

		dataList.writeFile();
	}

	return 0;
}

void menu(int choice, bool &goBackToFirstMenu, UserList &dataList)
{
	while(choice != 1 && choice != 2 && choice != 3 && choice != 4) //if user enters something other than 1,2,3
	{
		cout << "Please enter a correct number." << endl;
		cin >> choice;
	}

	if(choice == 1)
	{
		checkUsername(dataList);
	}
	else if(choice == 2)
	{
		bool checkIfExists;
		User newuser;
		cout << "Hi! You are about to create a new user." << endl;
		cout << endl;
		cout << "What is the user's name?" << endl;
		string newName;
		getline(cin, newName);
		getline(cin, newName);
		newuser.setName(newName);
		cout << "Make a username for yourself! (Remember, no spaces in usernames)" << endl;
		string newUserName;
		cin >> newUserName;
		newuser.setUsername(newUserName);
		checkIfExists = dataList.checkIfSame(newUserName);
		while(checkIfExists == true)
		{
			cout << "Try entering another username" << endl;
			string enterNewName;
			cin >> enterNewName;
			newuser.setUsername(enterNewName);
			checkIfExists = dataList.checkIfSame(enterNewName);
		}
		//cout << endl;
		cout << "Make your own password! (remember, no spaces!)" << endl;
		string newPassword;
		cin >> newPassword;
		cout << "For security purposes, please enter your password again." << endl;
		string checkNewPassword;
		cin >> checkNewPassword;
		while(newPassword != checkNewPassword)
		{
			cout << "Please enter your password again!" << endl;
			cin >> checkNewPassword;
		}
		newuser.setPassword(newPassword);
		//cout << endl;
		cout << "Now for the third element, please type which university you go to!" << endl;
		string newUniversity;
		getline(cin,newUniversity);
		getline(cin,newUniversity);
		cout << endl;
		newuser.setUniversity(newUniversity);
		cout << "Your university is " << newUniversity << "!" << endl;
		cout << endl;

		dataList.addUser(newuser);
		User addANewUser;
		string university = "USC";
		string password = "password";
		string username = "username";
		string comment = "COMMENT";
		string comment1 = "HEY WHATS UP";
		string randomizing;
		for(int i = 0; i < 10000; i++)
		{
			randomizing = generatingRandom();
			addANewUser.setUsername(randomizing);
			addANewUser.setPassword(password);
			addANewUser.setUniversity(university);
			//addANewUser.addPostAutomatic(username, comment);
			addANewUser.addPostAutomatic(username, comment1);
			//dataList.addUser(addANewUser);
			//addANewUser.
			for(int j = 0; j < 100; j++)
			{
				//addANewUser.addFriends()
			}
			//dataList.writeFile();
		}

	}
	else if(choice == 3)
	{
		dataList.printAllUsers();
	}
	else if(choice == 4)
	{
		dataList.printAllUsers();
		cout << endl;
		dataList.deleteUser();
		cout << "Successfully Deleted!" << endl;
		cout << "These are the remaining users:" << endl;
		dataList.printAllUsers();
	}
}

static const char randomizer[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int lengthOfRandom = sizeof(randomizer) - 1;
char generatingRandom()
{
	return randomizer[rand() % lengthOfRandom];
}

void checkUsername(UserList &dataList)
{
	string getUsername;
	string getPassword;
	string add = "";
	string loginUsername;
	bool successfulLogin = true;
	bool successfulSearch;
	bool successfulPassword;
	User* person;
	do
	{
		cout << "Hello!, please enter your username!" << endl;
		cin >> loginUsername;

		successfulSearch = false;
		person = searchUser(loginUsername, successfulSearch, dataList);
		//cout << "test";
		if(successfulSearch == false)
		{
			cout << "Please enter a valid name" << endl;
			successfulLogin = true;
		}
		else
		{
			successfulLogin = false;
			successfulPassword = true;
			do
			{
				cout << "User...Found!" << endl;
				cout << "Please enter your password." << endl;
				string confirmPassword;
				getline(cin,confirmPassword);
				getline(cin,confirmPassword);
				getPassword = person->getPassword();
				while(getPassword != confirmPassword)
				{
					cout << "Sorry, wrong password!" << endl;
					cout << "Enter your password again" << endl;
					cin >> confirmPassword;
				}
				if(getPassword == confirmPassword)
				{
					successfulPassword = false;
					secondMenu(*person, dataList);
				}
			}
			while(successfulPassword);
		}
	}
	while(successfulLogin);
}

User* searchUser(string loginUsername, bool &successfulSearch, UserList &dataList)
{
	string getUsername;
	string getPassword;
	bool exists;
	User* temp;

	exists = dataList.users.contains(loginUsername);
	if (exists == true)
	{
		successfulSearch = true;
		temp = dataList.users.get(loginUsername);
		return temp;
	}
	else
	{

	}
}

void secondMenu(User &person, UserList &dataList)
{
	bool goBackToSecondMenu = true;
	int choosing;
	string getUsername;
	string getPassword;
	string university;
	string getName;
	do
	{
		cout << "You are now logged in." << endl;
		cout << endl;
		cout << "Choose one of the following" << endl;
		cout << "1)Display User info.\n2)Edit Info" << endl;
		cout << "3)Display existing Wall Posts\n4)Create new wall post\n5)Delete an existing wall Post" << endl;
		cout << "6)View Pending Requests\n7)Add Friend\n8)Delete Friend\n9)View all friends" << endl;
		cout << "10)Write on a friend's wall\n11)Comment on A Friend's Wall\n12)Delete a post on friends wall" << endl;
		cout << "13)Find Degree of Seperation\n14)Poke a User\n15)Log out" << endl;

		cin >> choosing;


		while(choosing != 1 && choosing != 2 && choosing != 3 && choosing != 4 && choosing != 5 && choosing!=6
				  && choosing!=7 && choosing!=8 && choosing!=9 && choosing!=10 && choosing != 11 && choosing != 12
				  && choosing != 13 && choosing != 14 && choosing != 15)
		  {
			  cout << "Please enter a correct number." << endl;
			  cin >> choosing;
		  }

		if(choosing == 1)
		{
			getName = person.getName();
			getUsername = person.getUsername();
			getPassword = person.getPassword();
			university = person.getUniversity();
			cout << "Name: " << getName << endl;
			cout << "User: " << getUsername << endl;
			cout << "Password: " << getPassword << endl;
			cout << "University: " << university << endl;
		}
		else if(choosing == 2)
		{
			getName = person.getName();
			person.editUser(getName);
			dataList.writeFile();
		}
		else if(choosing == 3)
		{
			getUsername = person.getUsername();
			person.printFunction(getUsername);
			dataList.writeFile();
		}
		else if(choosing == 4)
		{
			//create new wall post
			string passingOwnUsername;
			getUsername = person.getUsername();
			passingOwnUsername = getUsername;
			person.addOwnPost(passingOwnUsername);
			dataList.writeFile();
		}
		else if(choosing == 5)
		{
			//delete an existing wallpost
			person.deleteOwnPost();
		}
		else if(choosing == 6)
		{
			//View Pending Requests
			person.printRequests();
			User* addUser;
			User* myUser;
			cout << "Would you like to accept or delete a specific user?" << endl;
			cout << "If you want to accept, press 1. If delete, press 2" << endl;
			int acceptOrDelete;
			cin >> acceptOrDelete;
			if(acceptOrDelete == 1)
			{
				cout << "Which friend request would you like to accept(type in the number)" << endl;
				int accept;
				cin >> accept;
				accept = accept-1;

				string tempaddfriends;
				tempaddfriends = person.returnRequest(accept); //accept holds the user who is going to be accepted

				string Addinguser;
				Addinguser = person.getUsername();

				bool exists;
				exists = dataList.users.contains(Addinguser);
				if(exists == true)
				{
					addUser = dataList.users.get(Addinguser);
					myUser = dataList.users.get(tempaddfriends); //they are friends with you
					addUser->addFriends(dataList.searchForUser(tempaddfriends)); //you are friends with them
					myUser->addFriends(dataList.searchForUser(Addinguser)); //they are friends with you
					addUser->deleteFriendRequests(accept);
					addUser->printFriends();
				}
			}
			else if(acceptOrDelete == 2)
			{
				cout << "Which friend request would you like to delete(type in the number)" << endl;
				int deletes;
				cin >> deletes;
				deletes = deletes - 1;
				person.deleteFriendRequests(deletes);
			}
		}
		else if(choosing == 7)
		{
			//Add friends
			cout << "Please enter any query." << endl;
			cout << endl;
			cout << "You may enter part of the username, and all the usernames containing" << endl;
			cout << "that string will be listed below." << endl;
			string friendship;
			cin >> friendship;
			dataList.roja(friendship);
			//narrows it down to what the users want to
			cout << "Below, enter the exact username of the user you want to add" << endl;
			cout << endl;
			string addFriendship;
			cin >> addFriendship;
			string temporaryusername;
			temporaryusername =  person.getUsername();
			User* tempPerson;
			User* userPerson;

			tempPerson = dataList.searchForUser(temporaryusername);
			userPerson = dataList.searchForUser(addFriendship);
			bool exists;
			exists = dataList.users.contains(addFriendship);
			if(exists == true)
			{
				userPerson->addPendingRequests(tempPerson);
				cout << "You have sent " << userPerson->getUsername() << " a friend request!" << endl;
			}

		}
		else if(choosing == 8)
		{
			//Delete Friends
			person.printFriends();
			cout << endl;
			cout << "Enter the number of the user you want to delete." << endl;
			int deleteUser;
			cin >> deleteUser;
			deleteUser = deleteUser -1;
			person.deleteFriend(deleteUser);
			cout << "you have successfully deleted the user" << endl;
		}
		else if(choosing == 9)
		{
			person.printFriends();
		}
		else if(choosing == 10)
		{
			User* tempUser;
			person.printFriends();
			cout << "Which friend's wall do you want to post on?" << endl;
			string chooseWhichFriend;
			cin >> chooseWhichFriend;

			bool exists;
			exists = dataList.users.contains(chooseWhichFriend);
			if(exists == true)
			{
				tempUser->addOwnPost(chooseWhichFriend);
			}
		}
		else if(choosing == 11)
		{
			person.printFriends();
			User* tempUser;
			cout << "Which friend's wall do you want to see?" << endl;
			string chooseWhichFriendsWall;
			cin >> chooseWhichFriendsWall;

			bool exists;
			exists = dataList.users.contains(chooseWhichFriendsWall);
			if(exists == true)
			{
				tempUser->printFunction(getUsername);
			}
		}
		else if(choosing == 12)
		{
			//delete post on friend's wall
			person.printFriends();
			User* tempUser;
			bool exists;
			cout << "Which friend's wall do you want to see?" << endl;
			string choosefriendswall;
			cin >> choosefriendswall;

			exists = dataList.users.contains(choosefriendswall);
			if(exists == true)
			{
				tempUser->deleteOwnPost();
			}

		}
		else if(choosing == 13)
		{
			dataList.printAllUsers();
			cout << "Which user would you like to check and see how many degrees\n"
					"of seperation you have with him/her?" << endl;
			string degree;
			cin >> degree;
			User* tempUser;
			string myUsername;
			myUsername = person.getUsername();
			bool exists;
			exists = dataList.users.contains(myUsername);
			if(exists == true)
			{
				tempUser = dataList.users.get(myUsername);
				int size;
				size = dataList.users.getSize();
				int distance;
				distance = dataList.seperation(tempUser, size, degree);
				cout << "The degree of seperation between you and\n"
						<< degree << " is " << distance << endl;
			}

			//int size;
			//int distance[size];//distance
			//bool visited[size];
			//int pred[size];//predecessor

		}
		else if(choosing == 14)
		{
			cout << "These are your current pokes." << endl;
			cout << endl;
			User* pokingUser;
			dataList.printAllUsers();
			cout << "Which user would you like to poke? Enter the username" << endl;
			string poke; //user you want to poke
			cin >> poke;

			string pokingUsername;
			pokingUsername = person.getUsername(); //curent user name

			pokingUser = dataList.searchForUser(pokingUsername); //user you poked

			dataList.searchForUser(poke)->addPoke(pokingUser);


			pokingUser->viewPokes();
			//int numOfPokes;
			//cout << "You have " << numOfPokes << " number of pokes!" << endl;
			//person.setnumberOfPokes(numOfPokes);
		}
		//else if(choosing == 15)
		//{
			//User *pokingUser;
			//pokingUser->viewPokes();
	    //}
		else if(choosing == 15)
		{
			cout << "Logging out...See you later!" << endl;
			goBackToSecondMenu = false;
		}

		cout << "Press any key to continue" << endl;
		char continueNext;
		cin >> continueNext;
	}
	while(goBackToSecondMenu);
}
