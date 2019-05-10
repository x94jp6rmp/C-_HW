#include "ScienceStudent.h"
#include <string>
ScienceStudent::ScienceStudent()
{
    _discipline = "";
    _course = "";
}
ScienceStudent::ScienceStudent(const ScienceStudent& theScienceStudent): Student(theScienceStudent)//初始化
{
    _discipline = theScienceStudent._discipline;
    _course = theScienceStudent._course;
}
ScienceStudent::ScienceStudent(string universityName, int number, UniversityStaff proctor, string discipline, string course): Student(universityName, number, proctor)//初始化
{
    _discipline = discipline;
    _course = course;
}
ScienceStudent& ScienceStudent::operator=(const ScienceStudent& scienceStudent)
{
    ScienceStudent::operator=(scienceStudent);
    _discipline = scienceStudent._discipline;
    _course = scienceStudent._course;
    return *this;
}
string ScienceStudent::GetDiscipline()//取得學生的discipline
{
    return _discipline;
}
string ScienceStudent::GetCourse()//取得學生的course
{
    return _course;
}
