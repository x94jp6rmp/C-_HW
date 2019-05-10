/*
Author: 賴玟君
ID: 105590047
Class: 資工三
Homework number：5
Date of the homework：2018/10/16
Purpose:可以新增,印出,搜尋,刪除選手及分數的程式
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Player.h"


using namespace std;

void PrintOption()//印出指令選項
{
    cout << "Please choose an action to do： " << endl;
    cout << "1. Add a new player and score. " << endl;
    cout << "2. Print all player names and their scores. " << endl;
    cout << "3. Search a player's score by name. " << endl;
    cout << "4. Delete a player by name. " << endl;
    cout << "5. Exit. " << endl;
    cout << ">> ";
}
bool IsNumber(string input)//判斷輸入是否為整數數字
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
int ChooseOption()//選擇指令
{
    stringstream inputStream;
    string input;
    double option;
    PrintOption();
    cin >> input;

    if (IsNumber(input))//檢查輸入是否為數字
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
            cout << endl << "請輸入正確的指令！(整數1-5)" << endl << endl;
        }
    }
    else
    {
        cout << endl << "請輸入正確的指令！(整數1-5)" << endl << endl;
    }

    inputStream.str("");
    inputStream.clear();
}
int SearchName(string name, vector<Player> playerInformation)//搜尋清單內是否有一樣的名字
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
vector<Player> AddPlayer(vector<Player> playerInformation)//增加選手及分數
{
    stringstream inputStream;
    string name;
    string scoreInput;
    int score = -1;
    int sameName;
    Player player(name, score);
    cout << "Please enter the player name: " << endl << ">> ";
    cin >> name;

    while (1)//判斷分數是否輸入錯誤 若錯誤就打到對為止
    {
        inputStream.str("");
        inputStream.clear();
        cout << "Please enter the score: " << endl << ">> ";
        cin >> scoreInput;

        if (IsNumber(scoreInput))
        {
            inputStream << scoreInput;
            inputStream >> score;

            if (score < 0)cout << endl << "請輸入正整數！(輸入小數自動省略小數位)" << endl;
            else break;
        }
        else cout << endl << "請輸入正整數！(輸入小數自動省略小數位)" << endl;
    }


    sameName = SearchName(name, playerInformation);

    if (sameName >= 0 && sameName < 10)
    {
        cout << "選手已在清單內" << endl << endl;
    }
    else
    {
        player.Set(name, score);
        playerInformation.push_back(player);//傳進vector
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

    while (option != 5)//可以循環輸入 直到輸入5離開
    {
        option = ChooseOption();

        switch (option)
        {
            case 1://新增選手和分數
                if (playerInformation.size() >= 10)
                {
                    cout << "已輸入滿10個選手，無法再輸入" << endl << endl;
                    break;
                }

                playerInformation = AddPlayer(playerInformation);
                break;

            case 2://印出所有選手和分數
                if (playerInformation.empty())cout << "目前沒有資料" << endl;

                for (int i = 0; i < playerInformation.size(); i++)
                {
                    cout << "[Player Info] name: " << playerInformation[i].GetName() <<  ", score: " << playerInformation[i].GetScore() << "." << endl ;
                }

                cout << endl;
                break;

            case 3://搜尋指定選手的分數
                if (playerInformation.empty())
                {
                    cout << "目前沒有輸入任何選手喔" << endl << endl;
                    break;
                }

                cout << "Please enter the player name you want to search:" << endl << ">>";
                cin >> name;
                sameName = SearchName(name, playerInformation);

                if (sameName == -1)
                {
                    cout << "查無此人" << endl << endl;
                }
                else
                {
                    cout << "[Player Info] name: " << playerInformation[sameName].GetName() << ", score: " << playerInformation[sameName].GetScore() << "." << endl << endl;
                }

                break;

            case 4://刪除指定選手
                if (playerInformation.empty())
                {
                    cout << "目前沒有輸入任何選手喔" << endl << endl;
                    break;
                }

                cout << "Please enter the player name you want to delete: " << endl << ">>";
                cin >> name;
                sameName = SearchName(name, playerInformation);

                if (sameName == -1)
                {
                    cout << "查無此人" << endl << endl;
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