#include "PrimeNumber.h"
PrimeNumber::PrimeNumber()
{
	primeNumber = 1;//若沒有初始化則設定初始值為1
}
PrimeNumber::PrimeNumber(int inputNumber)//初始化
{
	primeNumber = inputNumber;
}
int PrimeNumber::GetPrimeNumber()//取得質數
{
	return primeNumber;
}
PrimeNumber PrimeNumber::operator++()
{
	if (primeNumber < 3)
	{
		return 0;
	}
	else
	{
	primeNumber = ComputeNextPrimeNumber(primeNumber);
	return primeNumber;
	}

}
PrimeNumber PrimeNumber::operator--()
{
	if (primeNumber < 3)
	{
		return 0;
	}
	else if (primeNumber == 3)
	{
		return 2;
	}
	else
	{
		primeNumber = ComputeLastPrimeNumber(primeNumber);
		return primeNumber;
	}

}
ostream& operator <<(ostream& outStream, PrimeNumber primeNumber)
{
	outStream <<primeNumber.GetPrimeNumber();
	return outStream;
}
int PrimeNumber::ComputeLastPrimeNumber(int primeNumber)//計算上一個質數
{
	int isPrimeNumber = 0;
	while (1)
	{
		primeNumber--;
		for (int i = 2; i < primeNumber; i++)
		{
			if (primeNumber%i == 0)
			{
				isPrimeNumber = 0;
				break;
			}
			else
			{
				isPrimeNumber = 1;
			}
		}
		if (isPrimeNumber == 1)return primeNumber;
	}
}
int PrimeNumber::ComputeNextPrimeNumber(int primeNumber)//計算下一個質數
{
	int isPrimeNumber = 0;
	while (1)
	{
		primeNumber++;
		for (int i = 2; i < primeNumber; i++)
		{
			if (primeNumber%i == 0)
			{
				isPrimeNumber = 0;
				break;
			}
			else
			{
				isPrimeNumber = 1;
			}
		}
		if (isPrimeNumber == 1)return primeNumber;
	}
}