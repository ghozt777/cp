#include <bits/stdc++.h>
using namespace std;

// getters are used to access private propertis of a class

class Test
{
	int a;
	int b;

public:
	Test()
	{
		this->a = 0;
		this->b = 0;
		return;
	}

	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	// since a is a private memeber inorder to access its value we need a function that returns the value for us ;
	int getA() // this is a getter function
	{
		return this->a;
	}
	void setA(int a)
	{ // also to mutate the value of a we need a function : this function is known as setter
		this->a = a;
		return;
	}
};

int main()
{
	Test t;
	Test t1(1, 2);
	// cout << t.a << " " ; // this will generate an error as a is a private memeber of class Test
	cout << "inital a : " << t1.getA() << endl;
	t1.setA(69);
	cout << "modified a : " << t1.getA() << endl;
	return 0;
}
