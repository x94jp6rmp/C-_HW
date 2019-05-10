#include "Weight.h"
#include <iostream>

using namespace std;

Weight::Weight()//初始化
{
    _weightPounds = 0;
    _weightKilograms = 0;
    _weightOunces = 0;
}
void Weight::SetWeightKilograms(double weightKilograms)
{
    _weightKilograms = weightKilograms;
}
void Weight::SetWeightPounds(double weightPounds)
{
    _weightPounds = weightPounds;
}
void Weight::SetWeightOunces(double weightOunces)
{
    _weightOunces = weightOunces;
}
void Weight::ConvertPounds()//轉換
{
    cout << "Weight in pounds: " << _weightPounds << " pounds" << endl;
    cout << "Weight in kilograms: " << _weightPounds / 2.21 << " kilograms" << endl;
    cout << "Weight in Ounces: " << _weightPounds * 16 << " ounces\n" << endl;
}
void Weight::ConvertKilograms()//轉換
{
    cout << "Weight in pounds: " << _weightKilograms * 2.21 << " pounds" << endl;
    cout << "Weight in kilograms: " << _weightKilograms << " kilograms" << endl;
    cout << "Weight in Ounces: " << _weightKilograms * 2.21 * 16 << " ounces\n" << endl;
}
void Weight::ConvertOunces()//轉換
{
    cout << "Weight in pounds: " << _weightOunces / 16 << " pounds" << endl;
    cout << "Weight in kilograms: " << _weightOunces / 16 / 2.21 << " kilograms" << endl;
    cout << "Weight in Ounces: " << _weightOunces << " ounces\n" << endl;
}