/*
Author: 賴玟君
ID: 105590047
Class: 資工三
Homework number：8
Date of the homework：2018/11/13
Purpose:輸入一個數字並尋找下一個和上一個質數
*/
#include <iostream>
#include "PrimeNumber.h"
using namespace std;

int main()
{
    PrimeNumber primeNumber(800), nextSmallerPrimeNumber, nextLargerPrimeNumber, tmpPrimeNumber;
    tmpPrimeNumber = primeNumber;
    nextSmallerPrimeNumber = --tmpPrimeNumber;
    tmpPrimeNumber = primeNumber;
    nextLargerPrimeNumber = ++tmpPrimeNumber;
	cout << "Current Prime Number is : " << primeNumber << endl;
	cout << "Smaller one is : " << nextSmallerPrimeNumber << endl;
	cout << "Larger one is : " << nextLargerPrimeNumber << endl;
    system("pause");
    return 0;
}
