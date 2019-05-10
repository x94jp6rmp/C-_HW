#include "Student.h"
#include "UniversityStaff.h"
#include <string>
using namespace std;
Student::Student()
{
    _universityName = "";
    _number = 0;
    _proctor = UniversityStaff();
}
Student::Student(string universityName, int number, UniversityStaff proctor)
{
    _universityName = universityName;
    _number = number;
    _proctor = proctor;
}
Student::Student(const Student& theStudent)//初始化
{
    _universityName = theStudent._universityName;
    _number = theStudent._number;
    _proctor = theStudent._proctor;
}
Student& Student::operator=(const Student& student)
{
    _universityName = student._universityName;
    _number = student._number;
    _proctor = student._proctor;
    return *this;
}
string Student::GetUniversityName()//取得學校名
{
    return _universityName;
}
int Student::GetStudentNumber()//取得學號
{
    return _number;
}
UniversityStaff Student::GetProctorName()//取得proctor
{
    return _proctor;
}
