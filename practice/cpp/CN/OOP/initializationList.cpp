#include <bits/stdc++.h>
using namespace std;

class Foo
{
    const int a; // const value can't be reinitialized
    string foo;
    string &fooRef; // reference to foo and hence cant be reassigned

public:
    // Foo(int a , string foo){ <- this is not allowed as const data members need to be initialized when they are created and hence can't be reinitialized
    //     this->a = a ;
    //     this->foo = foo ;
    // }

    // to solve the above problem we can use initialization list :

    // we can't reassign values to reference variables and constant variables

    Foo(int a, string foo) : a(a), fooRef(this->foo)
    { // this is called initialization list
        this->foo = foo;
    }
    void disp()
    {
        cout << this->fooRef << " " << this->a << endl;
    }

    void alter_a()
    {
        // this->a++; // this will throw an error as a is a constant variable
        cout << "can't alter `a` as `a` is constant !" << endl;
        return;
    }
};

int main()
{
    Foo f(69, "Foo");
    f.disp();
    return 0;
}