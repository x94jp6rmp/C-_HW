/*
Author: �ળ�g
ID: 105590047
Class: ��u�T
Homework number�G10
Date of the homework�G2018/11/27
Purpose:�m���~�Ӫ��Ϊk�νm��operator overload
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