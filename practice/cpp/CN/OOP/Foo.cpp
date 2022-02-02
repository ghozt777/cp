#include <iostream>

// default copy constructor uses shallow copy which is undesired
// creating our own copy constructor

class Foo
{
    char *fooStr;
    int fooInt;

public:
    Foo(char *fooStr, int fooInt)
    {
        this->fooStr = fooStr;
        this->fooInt = fooInt;
    }

    Foo(char *fooStr, int fooInt, bool isDeepCopy)
    {
        if (isDeepCopy)
        {
            int n = strlen(fooStr);
            this->fooStr = new char[n + 1];
            strcpy(this->fooStr, fooStr);
            this->fooInt = fooInt;
        }
        else
        {
            // shallow copy
            this->fooStr = fooStr;
            this->fooInt = fooInt;
        }
    }

    Foo(Foo &f)
    { // overwritten copy constructor
        int n = strlen(f.fooStr);
        this->fooStr = new char[n + 1];
        strcpy(this->fooStr, f.fooStr);
        this->fooInt = f.fooInt;
    }

    // Foo(Foo &f) : Foo(f.fooStr, f.fooInt, true){} //delegating constructors are permitted only in C++11

    void disp()
    {
        std::cout << this->fooStr << ' ' << this->fooInt << std::endl;
    }

    void alterFoo(int pos, char c)
    {
        int n = strlen(this->fooStr);
        if (pos > n - 1)
        {
            std::cout << "overflow aborting!" << std::endl;
            return;
        }
        this->fooStr[pos] = c;
        return;
    }
};