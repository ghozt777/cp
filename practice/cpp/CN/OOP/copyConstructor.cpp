#include <bits/stdc++.h>
#include "./Test.cpp"
using namespace std;

// along with the default constructor the compiler also provides a copy contructor by default
// unlike the defaule constructor the copy constructor is still accessible even if we create our own constructor

int main()
{
    // Test t1 ; <- will throw an error
    Test t2(10);
    Test t3(t2); // created using copy constructor even tho we havent created one(static -> static)
    t2.disp();
    t3.disp();
    // dynamic creation :

    Test *t4 = new Test(20);
    // to use copy contructor using pointer we need to dereference it
    Test t5(*t4); // (dynamic->static)

    t4->disp();
    t5.disp();

    Test *t6 = new Test(*t4); // (dynamic->dynamic)
    t6->disp();

    Test *t7 = new Test(t2); // (static->dynamic)
    t7->disp();

    // copy assignment operator (=)

    Test t8(30);
    Test t9(40);

    t8.disp();
    t9.disp();

    t9 = t8; // copy assignment operator
    // new value
    t9.disp();

    Test *t10 = new Test(69);
    Test t11(6969);

    t10->disp();
    t11.disp();

    t11 = *t10; // (dynamic->static)
    t11.disp();

    Test t12(101);
    Test *t13 = new Test(1001);

    t12.disp();
    t13->disp();

    *t13 = t12; //(static->dynamic)
    t13->disp();

    return 0;
}