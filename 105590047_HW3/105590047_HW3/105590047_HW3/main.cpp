/*
Author: 賴玟君
ID: 105590047
Class: 資工三
Purpose:座標實作
*/

#include <iostream>
#include <cstdlib>
#include <sstream>//用stringstream轉型成功與否判斷輸入是否為數字
#include <string>

using namespace std;

class Point
{
    public:
        void Set(int x, int y);
        void Move(int dx, int dy);
        void Rotate90();
        int GetX();
        int GetY();
    private:
        int _x, _y;//座標的x與y
};

void Point::Set(int x, int y)//設定座標
{
    _x = x;
    _y = y;
}
void Point::Move(int dx, int dy)//移動座標
{
    _x = dx;
    _y = dy;
}
void Point::Rotate90()//旋轉90度
{
    int temp;
    temp = _x;
    _x = _y;
    _y = temp;
}
int Point::GetX()//取得x座標
{
    return _x;
}
int Point::GetY()//取得y座標
{
    return _y;
}

int Rounding(double number)//四捨五入至整數位
{
    if (number > 0)
    {
        number = number + 0.5;
        return static_cast<int>(number);
    }
    else
    {
        number = number - 0.5;
        return static_cast<int>(number);
    }
}
double IsError(string input)//判斷輸入是否為數字並轉字串為double，若輸入錯誤擇輸入至正確為止
{
    stringstream ss(input);
    double d;
    ss >> d;

    while (!ss || d ==0)//若轉型失敗代表不是數字，重新輸入
    {
        cout << "輸入錯誤，請重新輸入： ";
        ss.clear();
        ss.str("");
        cin >> input;
        stringstream ss(input);
        ss >> d;
    }

    return d;
}
void Input()//輸入
{
    string input;
    double x, y;
    double dx, dy;
    Point point;
    cout << "Please input coordinate X : ";
    cin >> input;
    x = IsError(input);//若輸入為數字將數值存入x
    cout << "Please input coordinate Y : ";
    cin >> input;
    y = IsError(input);//若輸入為數字將數值存入y
    point.Set(Rounding(x), Rounding(y));//設定座標
    cout << "Current coordinate is (" << point.GetX() << ", " << point.GetY() << ")." << endl;
    cout << "Move coordinate X to : ";
    cin >> input;
    dx = IsError(input);//若輸入為數字將數值存入dx
    cout << "Move coordinate Y to : ";
    cin >> input;
    dy = IsError(input);//若輸入為數字將數值存入dy
    point.Move(Rounding(dx), Rounding(dy));//移動座標到
    cout << "Current coordinate is (" << point.GetX() << ", " << point.GetY() << ")." << endl;
    point.Rotate90();//旋轉九十度
    cout << "After rotate 90, current cooradinate is (" << point.GetX() << ", " << point.GetY() << ").\n" << endl;
}

int main()
{
    while (1)//可以重複輸入
    {
        Input();
    }

    system("pause");
}