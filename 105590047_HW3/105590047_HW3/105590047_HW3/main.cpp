/*
Author: �ળ�g
ID: 105590047
Class: ��u�T
Purpose:�y�й�@
*/

#include <iostream>
#include <cstdlib>
#include <sstream>//��stringstream�૬���\�P�_�P�_��J�O�_���Ʀr
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
        int _x, _y;//�y�Ъ�x�Py
};

void Point::Set(int x, int y)//�]�w�y��
{
    _x = x;
    _y = y;
}
void Point::Move(int dx, int dy)//���ʮy��
{
    _x = dx;
    _y = dy;
}
void Point::Rotate90()//����90��
{
    int temp;
    temp = _x;
    _x = _y;
    _y = temp;
}
int Point::GetX()//���ox�y��
{
    return _x;
}
int Point::GetY()//���oy�y��
{
    return _y;
}

int Rounding(double number)//�|�ˤ��J�ܾ�Ʀ�
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
double IsError(string input)//�P�_��J�O�_���Ʀr����r�ꬰdouble�A�Y��J���~�ܿ�J�ܥ��T����
{
    stringstream ss(input);
    double d;
    ss >> d;

    while (!ss || d ==0)//�Y�૬���ѥN���O�Ʀr�A���s��J
    {
        cout << "��J���~�A�Э��s��J�G ";
        ss.clear();
        ss.str("");
        cin >> input;
        stringstream ss(input);
        ss >> d;
    }

    return d;
}
void Input()//��J
{
    string input;
    double x, y;
    double dx, dy;
    Point point;
    cout << "Please input coordinate X : ";
    cin >> input;
    x = IsError(input);//�Y��J���Ʀr�N�ƭȦs�Jx
    cout << "Please input coordinate Y : ";
    cin >> input;
    y = IsError(input);//�Y��J���Ʀr�N�ƭȦs�Jy
    point.Set(Rounding(x), Rounding(y));//�]�w�y��
    cout << "Current coordinate is (" << point.GetX() << ", " << point.GetY() << ")." << endl;
    cout << "Move coordinate X to : ";
    cin >> input;
    dx = IsError(input);//�Y��J���Ʀr�N�ƭȦs�Jdx
    cout << "Move coordinate Y to : ";
    cin >> input;
    dy = IsError(input);//�Y��J���Ʀr�N�ƭȦs�Jdy
    point.Move(Rounding(dx), Rounding(dy));//���ʮy�Ш�
    cout << "Current coordinate is (" << point.GetX() << ", " << point.GetY() << ")." << endl;
    point.Rotate90();//����E�Q��
    cout << "After rotate 90, current cooradinate is (" << point.GetX() << ", " << point.GetY() << ").\n" << endl;
}

int main()
{
    while (1)//�i�H���ƿ�J
    {
        Input();
    }

    system("pause");
}