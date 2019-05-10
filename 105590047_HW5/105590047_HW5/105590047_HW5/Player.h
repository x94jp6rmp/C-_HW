#pragma once
#ifndef playerdefine
#define playerdefine
#include <string>

using namespace std;

class Player
{
    public:
        Player(string name, int score);
        void Set(string name, int score);
        string GetName();
        int GetScore();
    private:
        string _name;
        int _score;
};



#endif

