#pragma once
#include <string>
using namespace std;
class UniversityStaff
{
    public:
        UniversityStaff();
        UniversityStaff(string theName);
        UniversityStaff(const UniversityStaff& theObject);
        string GetName() const;
        UniversityStaff& operator = (const UniversityStaff& rtSide);
        friend istream& operator >> (istream& inStream, UniversityStaff& staffObject);
        friend ostream& operator <<(ostream& outStream, const UniversityStaff& staffObject);
    private :
        string _name;
};