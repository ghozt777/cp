#include <bits/stdc++.h>
using namespace std;

// constant member functions are member functions which dont alter the props value
// hence constant functions are functions that only have side effects and don't perform any mutations on the data members
// a constant object of a class only has access to its constant member functions and can't access any other funciton that is not constant

class Foo
{
    int fooInt;
    string fooStr;
    const int id;

public:
    Foo(int fooInt, string fooStr, int id) : id(id)
    {
        this->fooInt = fooInt;
        this->fooStr = fooStr;
    }

    void inc() // not a constant funciton
    {
        this->fooInt++;
    }

    void disp() const // constant meber funciton
    {
        cout << "id: " << this->id << " data :  " << this->fooInt << " " << this->fooStr << endl;
        return;
    }
};

int main()
{
    Foo f1(10, "Foo 1", 1);
    Foo const f2(10, "Foo 2", 2); // constant object of a class
    f1.inc();                     // allowed
    // f2.inc() ; // this is not allowed as f2 dosen't have access to inc function as it is not a constant function
    f1.disp();
    f2.disp();
    return 0;
}