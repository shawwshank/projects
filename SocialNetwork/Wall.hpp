#ifndef WALL_CPP
#define WALL_CPP

#include "Wall.h"
//#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <time.h>

using namespace std;

Wall::Wall()
{
	//Post =  new LinkedList<WallPost>();
}

Wall::~Wall()
{

}

void Wall::addPost(string const name)//adds a post to the wall
{
	 WallPost wallpost;
	 cout << "Enter your post" << endl;
	 string comment;
	 getline(cin, comment);
	 getline(cin,comment);
	 wallpost.SetPost(comment);
	 wallpost.SetAuthor(name);
	// string date;
	// cout << "What is the date?" << endl;
	// getline(cin,date);
	 time_t clock;
	 string currentTime;
	 string storeAsString;
	 time(&clock);//gets current time
	 currentTime = ctime(&clock);
	 cout << currentTime;
	 wallpost.setDate(clock);
	 wallpost.setTime(currentTime);

	string hello;
	wallpost.printPost();
	Post.push_back(wallpost);
}

void Wall::automaticAdd(string const name, string const comment)
{
	 WallPost wallpost;
	 wallpost.SetPost(comment);
	 wallpost.SetAuthor(name);
	 time_t clock;
	 string currentTime;
	 string storeAsString;
	 time(&clock);//gets current time
	 currentTime = ctime(&clock);
	 //cout << currentTime;
	 wallpost.setDate(clock);
	 wallpost.setTime(currentTime);
}

void Wall::removePost()//removes a post from a wall
{
	string post;
	int iterator = 1;
	for(unsigned int i = 0; i < Post.size(); i++)
	{
		cout << iterator << " " << post;
		Post[i].printPost();
		iterator++;
	}
	cout << "Enter the number/position of the post you want to delete" << endl;
	int number;
	cin >> number;
	number = number - 1;
    Post.erase(Post.begin() + number);
}

void Wall::printPosts(string const name)
{
	string post;
	int iterator = 1;
	string comment;
	cout << "Do you want to sort by when:\n"
			"1)The post was originally made\n"
			"2)Most recent activity on post\n"
			"Enter either 1 or 2 to proceed." << endl;
	int selectTypeOfSort;
	cin >> selectTypeOfSort;
	while(selectTypeOfSort != 1 && selectTypeOfSort != 2)
	{
		cout << "Please enter a valid entry." << endl;
		cin >> selectTypeOfSort;
	}
	if(selectTypeOfSort == 1)
	{
		SelectionSortFirstOrder();
	}
	else if(selectTypeOfSort == 2)
	{
		SelectionSortSecondOrder();
	}
	for(unsigned int i = 0; i < Post.size(); i++)
	{
		post = Post[i].returnData();
		cout << iterator << ": " << post;
		Post[i].printPost();
		iterator++;
	}
	cout << "Do you want to 1)add or 2)delete a comment or 3)go back to menu?" << endl;
	int userChoice;
	cin >> userChoice;
	//the above is printing all the posts and all the comments on that post
	if(userChoice != 1 && userChoice != 2 && userChoice !=3)
	{
		cout << "Please enter a valid choice. " << endl;
		cin >> userChoice;
	}
	else if(userChoice == 1)
	{

			cout << "What post do you want to comment on? (Enter a number)" << endl;
			int numberComment;
			cin >> numberComment;
			cin.ignore();
			int iterator = 1;
			for(unsigned int i = 0; i < Post.size(); i++)
			{
				if(numberComment == iterator)
				{
					Post[i].addComment(name);
				}
				//then not this post, so iterator goes up by one
				iterator = iterator + 1;
			}
	}
	else if(userChoice == 2)
	{
			cout << "What is the number of the post that contains the comment"
					" you want to delete(Enter a number)?" << endl;
			int commentDelete;
			cin >> commentDelete;
			int goThrough = 1;
			cin.ignore();
			for(unsigned int i = 0; i < Post.size(); i++)
			{
				if(commentDelete == goThrough)
				{
					Post[i].removeComment();
				}
				goThrough = goThrough + 1;
			}
	}
	else if(userChoice == 3)
	{
		cout << "Going back to menu..." << endl;
	}
}

void Wall::SelectionSortFirstOrder()
{
	int firstElement;
	double diff;
	WallPost swapping;
	for(int i = Post.size() - 1; i > 0; i--)
	{
		firstElement = 0;
		for(int j = 1; j <= i; j++)
		{
			diff = difftime(Post[j].getDate(), Post[firstElement].getDate());
			if(diff < 0)
			firstElement = j;
		}
			//second element is greater than first, so second is more recent
			swapping = Post[firstElement];
			Post[firstElement] = Post[i];
			Post[i] = swapping;
	}
}

void Wall::SelectionSortSecondOrder()
{
	int firstElement;
	double diff;
	WallPost swapping;
	for(int i = Post.size() - 1; i > 0; i--)
	{
		firstElement = 0;
		for(int j = 1; j <= i; j++)
		{
			diff = difftime(Post[j].getLastComment(), Post[firstElement].getLastComment());
			if(diff < 0)
			firstElement = j;
		}
			//second element is greater than first, so second is more recent
			swapping = Post[firstElement];
			Post[firstElement] = Post[i];
			Post[i] = swapping;
	}
}

string Wall::writeIntoString()//writes all posts on wall to a string
{
	//get every post from wall and write into a string
    string write = "";
    string post;
    string author;
    string time;
    string commentWrite = "";
    for(unsigned int i = 0; i < Post.size(); i++)
    {
    	post = Post[i].getPost();
    	author = Post[i].getAuthor();
    	time = Post[i].getTime();
    	commentWrite = Post[i].writeCommentIntoString();
    	write += post + '\n' + author + '\n' + time + commentWrite;//+ '\n';
    }

    string finalPass = write + "---" + '\n';
    return finalPass;
}

void Wall::getFile()
{
	init.writeCommentIntoString();
}
void Wall::readString(string s)//reads a string and writes to a file
{
	//convert into chars and every time it hits \n, increase counter. if counter is odd, then comment. if even, then author.
    string data;
    int counter = 0;
    WallPost agraWall;
    int stringSize = data.size();
    for(int i = 0; i<=stringSize; i++)
    {
    	data = data + s[i];
        if(s[i] == '\n')
        {
			counter++;
			if(counter%2 != 0)
			{
				agraWall.SetPost(data);
				data = "";
			}
			if(counter%2 == 0)
			{
				agraWall.SetAuthor(data);
				//addPost(agraWall);
				data = "";
			}
        }
		/*if(check1 == true && check2 == true)
		{
			addPost(agraWall);
			counter++;
		}*/
     }
 }

void Wall::printAll() const
{
	int counter =0;
	string comment;
	string post;

	for(unsigned int i = 0; i < Post.size(); i++)
	{
		counter++;
		comment = Post[i].getPost();
		post = Post[i].getAuthor();
		cout << "Counter: " << counter << " Comment: " << comment << endl;
		cout << "Counter: " << counter << " Author: " << post << endl;
	}
}
#endif // WALL_CPP
