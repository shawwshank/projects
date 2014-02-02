/*
 * WallpostComment.cpp
 *
 *  Created on: Nov 12, 2013
 *      Author: Shashank
 */

#include "WallpostComment.h"

WallpostComment::WallpostComment()
{
	comment = "";
	author = "";
	time = "";
}

WallpostComment::~WallpostComment()
{

}

string WallpostComment::getComment() const
{
	return comment;
}

string WallpostComment::getAuthorComment() const
{
	return author;
}

string WallpostComment::getTime() const
{
	return time;
}

void WallpostComment::setComment(string a)
{
	comment = a;
}

void WallpostComment::setAuthorComment(string a)
{
	author = a;
}

void WallpostComment::setTime(string a)
{
	time = a;
}
time_t WallpostComment::getDate() const
{
	return commentTime;
}
void WallpostComment::setDate(time_t a)

{
	commentTime = a;
}

string WallpostComment::printComment()
{
	string header;
	string temp;
	string temp1;
	string temp2;
	string temp3;
	string final;
	//header = "Wallpost Comments: " + '\n';
	temp = "   Comment: " + comment + '\n';
	temp1 = "   Author: " + author + '\n';
	//temp2 = "   Date: " + date + '\n';
	temp3 = "   Time: " + time + '\n';
	final = temp + temp1 + temp3;
	return final;
}
