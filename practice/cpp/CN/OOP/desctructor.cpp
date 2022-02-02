#include <bits/stdc++.h>
using namespace std;

// descructor has the same name as that of the class , it has no return type , and it take no input argument
// it starts with a special symbol (~) in front of its name

class Test
{
    int foo;

public:
    Test(int foo) { this->foo = foo; }
    ~Test() { cout << "descructor called for foo =  " << this->foo << endl; }
    void disp() { std::cout << this->foo << std::endl; }
};

// its called just before the end of scope os a statically created object 
// for dynamically created objects we need to manually destruct them using delete operator

int main()
{
    Test t1(10);
    t1.disp();
    Test * t2 = new Test(11) ;
    delete t2 ;
    return 0;
}