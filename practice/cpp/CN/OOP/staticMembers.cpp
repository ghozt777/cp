#include <bits/stdc++.h>
using namespace std;

// static data members are still visible to member functions of a class
// static data members and functions can be accessed without creating anu object of that class and to access then we can use the scope resilution operator (::)

class Student
{
    const int roll;
    char *name;
    static int totalStudents; // this is a member of the class itslef and dosen't belong to any particular object
public:
    Student() : roll(-1)
    {
        totalStudents++;
        this->name = NULL;
        cout << "student created " << endl;
        cout << "Total Student count : " << totalStudents << endl;
    }

    Student(int roll, char *name) : roll(roll)
    {
        this->name = name;
        return;
    }

    int mutauteTotalStudents()
    {
        totalStudents++;
        return totalStudents * this->roll;
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }
};

// to initialize a static data member

int Student ::totalStudents = 0; // data_type class_name :: member_name = initial_value ;

int main()
{
    Student s1, s2, s3, s4, s5;
    cout << "Final number of Students  = " << Student::getTotalStudents() << endl;
    return 0;
}