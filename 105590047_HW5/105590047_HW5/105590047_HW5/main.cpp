/*
Author: �ળ�g
ID: 105590047
Class: ��u�T
Homework number�G5
Date of the homework�G2018/10/16
Purpose:�i�H�s�W,�L�X,�j�M,�R�����Τ��ƪ��{��
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Player.h"


using namespace std;

void PrintOption()//�L�X���O�ﶵ
{
    cout << "Please choose an action to do�G " << endl;
    cout << "1. Add a new player and score. " << endl;
    cout << "2. Print all player names and their scores. " << endl;
    cout << "3. Search a player's score by name. " << endl;
    cout << "4. Delete a player by name. " << endl;
    cout << "5. Exit. " << endl;
    cout << ">> ";
}
bool IsNumber(string input)//�P�_��J�O�_����ƼƦr
{
    stringstream inputStream(input);
    double doubleNumber;
    char character;

    if (!(inputStream >> doubleNumber)) return false;

    if (inputStream >> character) return false;

    return true;
    inputStream.str("");
    inputStream.clear();
}
int ChooseOption()//��ܫ��O
{
    stringstream inputStream;
    string input;
    double option;
    PrintOption();
    cin >> input;

    if (IsNumber(input))//�ˬd��J�O�_���Ʀr
    {
        inputStream << input;
        inputStream >> option;

        if (option - static_cast<int>(option) == 0 && option >= 1 && option <= 5)
        {
            cout << endl;
            return option;
        }
        else
        {
            cout << endl << "�п�J���T�����O�I(���1-5)" << endl << endl;
        }
    }
    else
    {
        cout << endl << "�п�J���T�����O�I(���1-5)" << endl << endl;
    }

    inputStream.str("");
    inputStream.clear();
}
int SearchName(string name, vector<Player> playerInformation)//�j�M�M�椺�O�_���@�˪��W�r
{
    for (int i = 0; i < playerInformation.size(); i++)
    {
        if (playerInformation[i].GetName() == name)
        {
            return i;
        }
    }

    return -1;
}
vector<Player> AddPlayer(vector<Player> playerInformation)//�W�[���Τ���
{
    stringstream inputStream;
    string name;
    string scoreInput;
    int score = -1;
    int sameName;
    Player player(name, score);
    cout << "Please enter the player name: " << endl << ">> ";
    cin >> name;

    while (1)//�P�_���ƬO�_��J���~ �Y���~�N����אּ��
    {
        inputStream.str("");
        inputStream.clear();
        cout << "Please enter the score: " << endl << ">> ";
        cin >> scoreInput;

        if (IsNumber(scoreInput))
        {
            inputStream << scoreInput;
            inputStream >> score;

            if (score < 0)cout << endl << "�п�J����ơI(��J�p�Ʀ۰ʬٲ��p�Ʀ�)" << endl;
            else break;
        }
        else cout << endl << "�п�J����ơI(��J�p�Ʀ۰ʬٲ��p�Ʀ�)" << endl;
    }


    sameName = SearchName(name, playerInformation);

    if (sameName >= 0 && sameName < 10)
    {
        cout << "���w�b�M�椺" << endl << endl;
    }
    else
    {
        player.Set(name, score);
        playerInformation.push_back(player);//�Ƕivector
        cout << "[Player Info] name: " << name << ", score: " << score << "." << endl;
        cout << "Add a new player and score successfully!" << endl << endl;
    }

    return playerInformation;
}
int main()
{
    vector<Player> playerInformation;
    int score = 0, option = 0, sameName;
    string name;
    Player player(name, score);

    while (option != 5)//�i�H�`����J �����J5���}
    {
        option = ChooseOption();

        switch (option)
        {
            case 1://�s�W���M����
                if (playerInformation.size() >= 10)
                {
                    cout << "�w��J��10�ӿ��A�L�k�A��J" << endl << endl;
                    break;
                }

                playerInformation = AddPlayer(playerInformation);
                break;

            case 2://�L�X�Ҧ����M����
                if (playerInformation.empty())cout << "�ثe�S�����" << endl;

                for (int i = 0; i < playerInformation.size(); i++)
                {
                    cout << "[Player Info] name: " << playerInformation[i].GetName() <<  ", score: " << playerInformation[i].GetScore() << "." << endl ;
                }

                cout << endl;
                break;

            case 3://�j�M���w��⪺����
                if (playerInformation.empty())
                {
                    cout << "�ثe�S����J�������" << endl << endl;
                    break;
                }

                cout << "Please enter the player name you want to search:" << endl << ">>";
                cin >> name;
                sameName = SearchName(name, playerInformation);

                if (sameName == -1)
                {
                    cout << "�d�L���H" << endl << endl;
                }
                else
                {
                    cout << "[Player Info] name: " << playerInformation[sameName].GetName() << ", score: " << playerInformation[sameName].GetScore() << "." << endl << endl;
                }

                break;

            case 4://�R�����w���
                if (playerInformation.empty())
                {
                    cout << "�ثe�S����J�������" << endl << endl;
                    break;
                }

                cout << "Please enter the player name you want to delete: " << endl << ">>";
                cin >> name;
                sameName = SearchName(name, playerInformation);

                if (sameName == -1)
                {
                    cout << "�d�L���H" << endl << endl;
                }
                else
                {
                    playerInformation.erase(playerInformation.begin() + sameName);
                    cout << "Player name: " << name << " has been deleted successfully!" << endl << endl;
                }

                break;
        }
    }

    system("pause");
    return 0;
}