/*
Author: �ળ�g
ID: 105590047
Class: ��u�T
Homework number�G6
Date of the homework�G2018/10/23
Purpose:Ū�ɨæL�X�S�����Ƥ������W��
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

void Input(set<string>& inputFile)//Ū�ɨæs�춰�X��
{
    fstream inputStream;
    char inputString[100];//�Ȧs���r���}�C
    inputStream.open("input.txt", ios::in);

    if (!inputStream)
    {
        cout << "�L�k�}��" << endl;
    }
    else
    {
        do
        {
            inputStream.getline(inputString, sizeof(inputString));//��Ū������Ȧs�}�C
            inputFile.insert(inputString);//�A�s�춰�X��
        }
        while (!inputStream.eof());//���󵲧��N���X�j��
    }

    inputStream.close();//����
}

int main()
{
    set<string> inputFile;
    cout << "Invitation List : " << endl;
    Input(inputFile);

    for (set<string>::iterator iter = ++inputFile.begin(); iter != inputFile.end(); ++iter)//�L�X���X��������
    {
        cout << *iter << endl;
    }

    cout << endl;
    system("pause");
}