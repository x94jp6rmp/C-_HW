#pragma once
#include <string>
#include "UniversityStaff.h"
using namespace std;
class Student
{
    public:
        Student();
        Student(string universityName, int number, UniversityStaff proctor);
        Student(const Student& theStudent);
        string GetUniversityName();
        int GetStudentNumber();
        UniversityStaff GetProctorName();
        Student& operator = (const Student& student);
    private:
        string _universityName;
        int _number;
        UniversityStaff _proctor;


};