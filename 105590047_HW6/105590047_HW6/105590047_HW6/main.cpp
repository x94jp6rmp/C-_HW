/*
Author: 賴玟君
ID: 105590047
Class: 資工三
Homework number：6
Date of the homework：2018/10/23
Purpose:讀檔並印出沒有重複元素的名單
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

void Input(set<string>& inputFile)//讀檔並存到集合中
{
    fstream inputStream;
    char inputString[100];//暫存的字元陣列
    inputStream.open("input.txt", ios::in);

    if (!inputStream)
    {
        cout << "無法開啟" << endl;
    }
    else
    {
        do
        {
            inputStream.getline(inputString, sizeof(inputString));//先讀取整行到暫存陣列
            inputFile.insert(inputString);//再存到集合中
        }
        while (!inputStream.eof());//到文件結尾就跳出迴圈
    }

    inputStream.close();//關檔
}

int main()
{
    set<string> inputFile;
    cout << "Invitation List : " << endl;
    Input(inputFile);

    for (set<string>::iterator iter = ++inputFile.begin(); iter != inputFile.end(); ++iter)//印出集合中的元素
    {
        cout << *iter << endl;
    }

    cout << endl;
    system("pause");
}