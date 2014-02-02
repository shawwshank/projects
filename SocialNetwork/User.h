#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Wall.hpp"
#include <vector>
using namespace std;

class User
{
    public:
        User();
        User(string name, string pass, string school);
        ~User();

        bool getSeperate();
        bool setSeperate(bool set);
        string getUsername() const;
        string getName() const;
        void setName(string setname);
        void setUsername(string username);
        string getPassword() const;
        void setPassword(string password);
        string getUniversity() const;
        void setUniversity(string university);
        void addPostAutomatic(string const name, string const comment);
        void addOwnPost(string const name);
        int getHash(int size);

        void addPoke(User* poker);
        void deletePoke(int const entry);
        void viewPokes();
        int getnumberOfPokes();
        void setnumberOfPokes(int number);

        void deleteOwnPost();
        void printFunction(string const name);
        User(string n);
        void editUser(string name);
        Wall setwall;

        void printRequests();
		void addPendingRequests(User* addUser); //adds request to bag
		void addFriends(User* friendship); //adds friend to bag
		string returnRequest(int const name);
	    void deleteFriendRequests(int const name);
	    string returnFriend(int const name);
		void deleteFriend(int const myName); //deletes friends from friend bag
	    void printFriends(); //displays all friends //goes in main


        vector<User*> friends; //string or int? choose string
        vector<User*> requests; //pending requests
        vector<User*> pokes;
    private:
        string username;
        string password;
        string university;
        string name;
        bool sep;
        int totalpokes;
};

#endif // USER_H
