#pragma once
#include <iostream>
using namespace std;
class PrimeNumber
{
    public:
        PrimeNumber();
        PrimeNumber(int inputNumber);
	    int GetPrimeNumber();
		int ComputeLastPrimeNumber(int primeNumber);
		int ComputeNextPrimeNumber(int primeNumber);
		PrimeNumber operator ++();
		PrimeNumber operator -- ();
		friend ostream& operator << (ostream& outStream, PrimeNumber primeNumber);
    private:
        int primeNumber=1;
};