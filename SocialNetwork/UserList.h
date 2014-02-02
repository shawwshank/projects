#ifndef USERLIST_H
#define USERLIST_H

#include "User.hpp"
#include "HashTable.hpp"
#include <queue>
using namespace std;

class UserList
{
    public:

		Hashtable<string, User> users;
        UserList();
        ~UserList();
        void addUser(User addtolist);
        void deleteUser();
        void writeFile();
        void readFile();
        void printAllUsers();
        bool checkIfSame(string username);
        int seperation(User* x, int size, string findName);

        User* searchForUser(string const &name); //searches for user
        void roja(string const &query); //ROJA FUNCTION


        //vector<User> user;
    private:
       // vector<User> userLogin;
       // User usingUser;

};



#endif // USERLIST_H
