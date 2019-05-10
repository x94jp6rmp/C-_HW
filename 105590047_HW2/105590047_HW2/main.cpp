/*
Author: 賴玟君
ID: 105590047
Class: 資工三
Purpose:模擬一個射擊生存遊戲，計算每種策略及每個人的勝率
*/

#include <iostream>
#include <cstdlib>//為了使用亂數
using namespace std;

const double ACCURACYAARON = 1.0 / 3;//宣告Aaron的準確率
const double ACCURACYBOB = 0.5;//宣告bob的準確率
const double ACCURACYCHARLIE = 1.0;//宣告charlie的準確率
const int DUENUM = 10000;

void shoot(bool& alive, double accuracy)  //射擊是否有射中
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
int startDuel()//一局遊戲
{
    bool aliveAaron = true, aliveBob = true, aliveCharlie = true;

    while ((aliveAaron && aliveBob) || (aliveBob && aliveCharlie) || (aliveCharlie && aliveAaron))//若剩下一人存活才跳出迴圈
    {
        if (aliveBob)//Bob存活並射擊倖存者
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

        if (aliveCharlie)//Charlie存活並射擊倖存者
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

        if (aliveAaron)//Aaron存活並射擊倖存者
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

    if (aliveAaron) return 0;//若Aaron生存則回傳0
    else if (aliveBob) return 1;//若Bob生存則回傳1
    else if (aliveCharlie) return 2;//若Charlie生存則回傳2
}
void main()
{
    int winner = 0;
    double winAaron = 0, winBob = 0, winCharlie = 0;

    for (int i = 0; i < DUENUM; i++)
    {
        winner = startDuel();

        if (winner == 0)//計算Aaron勝利次數
        {
            winAaron++;
        }
        else if (winner == 1)//計算Bob勝利次數
        {
            winBob++;
        }
        else if (winner == 2)//計算Charlie勝利次數
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