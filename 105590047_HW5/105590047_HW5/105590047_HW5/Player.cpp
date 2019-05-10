#include "Player.h"
Player::Player(string name, int score)
{
    _name = name;
    _score = score;
}


void Player::Set(string name, int score)
{
    _name = name;
    _score = score;
}
string Player::GetName()
{
    return _name;
}
int Player::GetScore()
{
    return _score;
}

