/*
Author: �ળ�g
ID: 105590047
Class: ��u�T
Purpose:�����@�Ӯg���ͦs�C���A�p��C�ص����ΨC�ӤH���Ӳv
*/

#include <iostream>
#include <cstdlib>//���F�ϥζü�
using namespace std;

const double ACCURACYAARON = 1.0 / 3;//�ŧiAaron���ǽT�v
const double ACCURACYBOB = 0.5;//�ŧibob���ǽT�v
const double ACCURACYCHARLIE = 1.0;//�ŧicharlie���ǽT�v
const int DUENUM = 10000;

void shoot(bool& alive, double accuracy)  //�g���O�_���g��
{
    double ran;

    if (alive == true)
    {
        ran = rand() % 100;

        if (ran < (accuracy * 100))
        {
            alive = false;
        }
    }
}
int startDuel()//�@���C��
{
    bool aliveAaron = true, aliveBob = true, aliveCharlie = true;

    while ((aliveAaron && aliveBob) || (aliveBob && aliveCharlie) || (aliveCharlie && aliveAaron))//�Y�ѤU�@�H�s���~���X�j��
    {
        if (aliveBob)//Bob�s���îg���Ʀs��
        {
            if (aliveCharlie)
            {
                shoot(aliveCharlie, ACCURACYBOB);
            }
            else if (aliveAaron)
            {
                shoot(aliveAaron, ACCURACYBOB);
            }
        }

        if (aliveCharlie)//Charlie�s���îg���Ʀs��
        {
            if (aliveBob)
            {
                shoot(aliveBob, ACCURACYCHARLIE);
            }
            else if (aliveAaron)
            {
                shoot(aliveAaron, ACCURACYCHARLIE);
            }
        }

        if (aliveAaron)//Aaron�s���îg���Ʀs��
        {
            if (aliveCharlie)
            {
                shoot(aliveCharlie, ACCURACYAARON);
            }
            else if (aliveBob)
            {
                shoot(aliveBob, ACCURACYAARON);
            }
        }
    }

    if (aliveAaron) return 0;//�YAaron�ͦs�h�^��0
    else if (aliveBob) return 1;//�YBob�ͦs�h�^��1
    else if (aliveCharlie) return 2;//�YCharlie�ͦs�h�^��2
}
void main()
{
    int winner = 0;
    double winAaron = 0, winBob = 0, winCharlie = 0;

    for (int i = 0; i < DUENUM; i++)
    {
        winner = startDuel();

        if (winner == 0)//�p��Aaron�ӧQ����
        {
            winAaron++;
        }
        else if (winner == 1)//�p��Bob�ӧQ����
        {
            winBob++;
        }
        else if (winner == 2)//�p��Charlie�ӧQ����
        {
            winCharlie++;
        }
    }

    cout << "Aaron's wins: " << winAaron << " times, winning rate: " << (winAaron / DUENUM) * 100 << "%" << endl;
    cout << "Bob's wins: " << winBob << " times, winning rate: " << (winBob / DUENUM) * 100 << "%" << endl;
    cout << "Charlie's wins: " << winCharlie << " times, winning rate: " << (winCharlie / DUENUM) * 100 << "%" << endl;
    system("pause");
    return;
}