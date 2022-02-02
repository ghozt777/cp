#include <bits/stdc++.h>
using namespace std;

// this holds the address of the current object
// constructor is a function that is called only once when an object of a class is created
// a constructor is provided by the compiler : default constructor
// wirting our own default constructor shadows the one provided by the compiler
// there also can be parameterized constructors :

// NOTE : as soon as we create our own constructor whether its paramererized or not it hides the compile one
// so in the below code even if we remove the constructor Test() with no arguments we will get an error !

class Test
{
private:
    string foo;

public:
    Test()
    { // shadows the one provided by the compiler
        cout << "Object created using default constructor " << endl;
        this->foo = "Default Value";
    }
    Test(string foo)
    {
        cout << "Object created using parameterized constructor " << endl;
        this->foo = foo; // this is used to point to the current object ;
    }
    void dispFoo()
    {
        cout << this->foo << endl;
        return;
    }
};

int main()
{
    Test t1;
    Test t2("Foo");
    t1.dispFoo();
    t2.dispFoo();
    return 0;
}