#ifndef WALLPOST_H
#define WALLPOST_H

#include <iostream>
#include "WallPostComment.h"
#include <vector>
#include <time.h>
using namespace std;

class WallPost
{
    public:
        WallPost();
        ~WallPost();
        string getPost() const;
        string getAuthor() const;
        time_t getDate() const;
        string getTime() const;
        time_t getLastComment() const;
        void SetPost(string comment);
        void SetAuthor(string poster);
        void setDate(time_t a);
        void setTime(string a);
        void printPost();
        string returnData();

        void addComment(string const name);
        void removeComment();
        string writeCommentIntoString();

    private:
        string comment;
        string poster;
        string date;
        string timeStamp;
        time_t currentTime;
        vector<WallpostComment> commentPost;
        WallpostComment initComment;

};

#endif // WALLPOST_H
