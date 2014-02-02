/*
 * WallpostComment.h
 *
 *  Created on: Nov 12, 2013
 *      Author: Shashank
 */

#ifndef WALLPOSTCOMMENT_H_
#define WALLPOSTCOMMENT_H_

using namespace std;
#include <iostream>
#include <time.h>

class WallpostComment {
public:
	WallpostComment();
	virtual ~WallpostComment();

	string getComment() const;
	void setComment(string a);

	string getAuthorComment() const;
	void setAuthorComment(string a);

	string getTime() const;
	void setTime(string a);

	time_t getDate() const;
	void setDate(time_t a);

	string printComment();
private:
	string comment;
	string author;
	string time;
	string date;
	time_t commentTime;
};

#endif /* WALLPOSTCOMMENT_H_ */
