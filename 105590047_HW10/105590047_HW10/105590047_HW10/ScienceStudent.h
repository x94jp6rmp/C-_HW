#pragma once
#include <string>
#include "Student.h"
class ScienceStudent : public Student
{
    public:
        ScienceStudent();
        ScienceStudent(const ScienceStudent& theScienceStudent);
        ScienceStudent(string universityName, int number, UniversityStaff proctor, string discipline, string course);
        string GetDiscipline();
        string GetCourse();
        ScienceStudent& operator=(const ScienceStudent& scienceStudent);
    private:
        string _discipline;
        string _course;
};