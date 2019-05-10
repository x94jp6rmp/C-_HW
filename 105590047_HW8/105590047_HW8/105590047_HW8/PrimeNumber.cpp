#include "PrimeNumber.h"
PrimeNumber::PrimeNumber()
{
	primeNumber = 1;//�Y�S����l�ƫh�]�w��l�Ȭ�1
}
PrimeNumber::PrimeNumber(int inputNumber)//��l��
{
	primeNumber = inputNumber;
}
int PrimeNumber::GetPrimeNumber()//���o���
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
int PrimeNumber::ComputeLastPrimeNumber(int primeNumber)//�p��W�@�ӽ��
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
int PrimeNumber::ComputeNextPrimeNumber(int primeNumber)//�p��U�@�ӽ��
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