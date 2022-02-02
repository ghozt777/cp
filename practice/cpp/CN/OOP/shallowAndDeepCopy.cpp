#include <bits/stdc++.h>
#include "./Foo.cpp"
using namespace std;

int main()
{
    char str[] = "foo";
    Foo f1(str, 69);
    f1.disp();
    str[1] = 'i';
    str[2] = 'i';
    Foo f2(str, 6969);
    f2.disp();
    f1.disp(); // change in prop `fooStr` as the memory location it points to underwent modification
    // this is known as shallow copy as we are not creating a new array and are simply passing the address of the 0th element :
    // hence str , f1.fooStr , f2.fooStr all point to the same array and any change made reflects in all of them

    // now using deep copy ;
    char str1[] = "foo";
    Foo f3(str1, 10, true);
    str1[1] = 'i';
    str1[2] = 'i';
    Foo f4(str1, 1010, true);
    cout << "using deep copy : " << endl;
    f3.disp();
    f4.disp();
    f3.disp();

    // using our own copy constructor that uses deep copy

    Foo f5(f3);
    f5.alterFoo(0, 'x');
    f3.disp();
    f5.disp();
    return 0;
}