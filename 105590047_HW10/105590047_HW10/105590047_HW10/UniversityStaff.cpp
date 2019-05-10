#include "UniversityStaff.h"
#include <iostream>
#include <string>
using namespace std;

UniversityStaff::UniversityStaff()
{
    _name = "";
}
UniversityStaff::UniversityStaff(const UniversityStaff& theObject)
{
    _name = theObject._name;
}
UniversityStaff::UniversityStaff(string theName)//初始化
{
    _name = theName;
}
string UniversityStaff::GetName() const//用常數傳出學校名
{
    return _name;
}
UniversityStaff& UniversityStaff::operator = (const UniversityStaff& rtSide)
{
    this->_name = rtSide._name;
    return *this;
}
istream& operator >> (istream& inStream, UniversityStaff& staffObject)
{
    inStream >> staffObject._name;
    return inStream;
}
ostream& operator <<(ostream& outStream, const UniversityStaff& staffObject)
{
    outStream << staffObject._name;
    return outStream;
}
