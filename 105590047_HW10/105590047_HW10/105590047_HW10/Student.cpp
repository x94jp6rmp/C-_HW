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
Student::Student(const Student& theStudent)//��l��
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
string Student::GetUniversityName()//���o�ǮզW
{
    return _universityName;
}
int Student::GetStudentNumber()//���o�Ǹ�
{
    return _number;
}
UniversityStaff Student::GetProctorName()//���oproctor
{
    return _proctor;
}
