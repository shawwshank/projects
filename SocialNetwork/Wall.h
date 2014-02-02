#ifndef WALL_H
#define WALL_H

#include "WallPost.h"
#include <iostream>
#include <vector>

class Wall
{
    public:
         Wall();
        ~Wall();
        void addPost(string const name);
        void automaticAdd(string const name, string const comment);
        void removePost();
        string writeIntoString();
        void readString(string s);
        void printPosts(string const name);
        void printAll() const;
        void SelectionSortFirstOrder();
        void SelectionSortSecondOrder();
        void getFile();
        WallPost init;
    private:
        vector<WallPost> Post;
};

#endif // WALL_H
