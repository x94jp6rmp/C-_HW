/*
Author: 賴玟君
ID: 105590047
Class: 資工三
Homework number：10
Date of the homework：2018/11/27
Purpose:練習繼承的用法及練習operator overload
*/


#include <iostream>
#include <string>
#include "UniversityStaff.h"
#include "ScienceStudent.h"
using namespace std;
int main()
{
    UniversityStaff proctor("wkc");
    ScienceStudent scienceStudent("NTUT", 123, proctor, "Computer Science", "Object-oriented analysis and design");
    cout << "<Student Information> \n";
    cout << "Student University : " << scienceStudent.GetUniversityName() << endl;
    cout << "Student Number : " << scienceStudent.GetStudentNumber() << endl;
    cout << "Student Proctor : " << scienceStudent.GetProctorName() << endl;
    cout << "Student Discipline : " << scienceStudent.GetDiscipline() << endl;
    cout << "Course : " << scienceStudent.GetCourse() << endl;
    system("pause");
    return 0;
}