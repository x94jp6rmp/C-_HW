/*
Author: �ળ�g
ID: 105590047
Class: ��u�T
Purpose:��쪺�ഫ
*/

#include <iostream>
#include <regex>
#include <string>
#include <cstdlib>
#include "Weight.h"

using namespace std;


void Input()//��J
{
    Weight weight;
    double WeightPounds = 0.0, WeightKilograms = 0.0, WeightOunces = 0.0;
    cout << "SetWeightPounds(inputWeight), inputWeight = ?\n>> ";
    cin >> WeightPounds;

    while (!cin || WeightPounds < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "SetWeightPounds(inputWeight), inputWeight = ?\n>> ";
        cin >> WeightPounds;
    }

    weight.SetWeightPounds(WeightPounds);
    weight.ConvertPounds();
    cout << "SetWeightKilograms(inputWeight), inputWeight = ?\n>> ";
    cin >> WeightKilograms;

    while (!cin || WeightKilograms < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "SetWeightKilograms(inputWeight), inputWeight = ?\n>> ";
        cin >> WeightKilograms;
    }

    weight.SetWeightKilograms(WeightKilograms);
    weight.ConvertKilograms();
    cout << "SetWeightOunces(inputWeight), inputWeight = ?\n>> ";
    cin >> WeightOunces;

    while (!cin || WeightOunces < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "SetWeightOunces(inputWeight), inputWeight = ?\n>> ";
        cin >> WeightOunces;
    }

    weight.SetWeightOunces(WeightOunces);
    weight.ConvertOunces();
}
int main()
{
    Input();
    system("pause");
}
