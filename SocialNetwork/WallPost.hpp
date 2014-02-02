#ifndef WALLPOST_CPP
#define WALLPOST_CPP

#include "WallPost.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;

WallPost::WallPost()//constructor
{
    comment = "";
    poster = "";
    timeStamp = "";
    currentTime = NULL;
}

WallPost::~WallPost()
{
    //dtor
}

string WallPost::getPost() const//getter for post
{
    return comment;
}
void WallPost::SetPost(string a)//setter for post
{
    comment = a;
}
string WallPost::getAuthor() const//getter for author
{
    return poster;
}
void WallPost::SetAuthor(string b)//setter for author
{
    poster = b;
}
void WallPost::setDate(time_t a)
{
	currentTime = a;
}
time_t WallPost::getDate() const
{
	return currentTime;
}
void WallPost::setTime(string a)
{
	timeStamp = a;
}
string WallPost::getTime() const
{
	return timeStamp;
}
time_t WallPost::getLastComment() const
{
	if(commentPost.size() == 0)
	{
		return 0;
	}
	else return commentPost[commentPost.size() -1].getDate();
}

void WallPost::printPost()//prints the post
{
	string name;
	cout << endl;
	cout << endl;
	for(unsigned int i = 0; i < commentPost.size(); i++)
	{
		name = commentPost[i].printComment();
		cout << name << endl;
	}
}
void WallPost::addComment(string const name)
{
	initComment.setAuthorComment(name);
	cout << "What is the comment you want to post?" << endl;
	string commentpost;
	getline(cin,commentpost);
	initComment.setComment(commentpost);

	time_t clock;
	string currentTime;
	string storeAsString;
	time(&clock);

	currentTime = ctime(&clock);
	cout << currentTime;

	initComment.setDate(clock);
	initComment.setTime(currentTime);

	//initComment.setTime(currentTime);
	commentPost.push_back(initComment);
}
void WallPost::removeComment()
{
	string comment;
	int iterator = 1;
	for(unsigned int i = 0; i < commentPost.size(); i++)
	{
		comment = commentPost[i].printComment();
		cout << iterator << " " << comment << endl;
		iterator++;
	}
	cout << "Enter the number/position of the post you want to delete." << endl;
	int number;
	cin >> number;
	number = number - 1;
	commentPost.erase(commentPost.begin() + number);
}
string WallPost::writeCommentIntoString() //writes all comments on post
{
	string write = "";
	string comment;
	string author;
	string time;
	string writeComments = "";
	//string addMarkerAfterComments = "--";
	for(unsigned int i = 0; i < commentPost.size(); i++)
	{
		comment = commentPost[i].getComment();
		author = commentPost[i].getAuthorComment();
		time = commentPost[i].getTime();
		write += comment + '\n' + author + '\n' + time;
	}

	string finalPass = write + '\n';// + "NEWUSER";
	return finalPass;
}
string WallPost::returnData()
{
	string final;
	final = "Post: " + comment + ",\n   Author: " + poster + ",\n   Date: " + timeStamp ;
	return final;
}

#endif // WALLPOST_CPP
