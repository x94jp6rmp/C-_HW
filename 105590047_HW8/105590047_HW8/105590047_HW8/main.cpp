/*
Author: �ળ�g
ID: 105590047
Class: ��u�T
Homework number�G8
Date of the homework�G2018/11/13
Purpose:��J�@�ӼƦr�ôM��U�@�өM�W�@�ӽ��
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
