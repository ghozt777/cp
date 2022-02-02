#include <bits/stdc++.h>
using namespace std;

class SimpleHashSet
{
    string *set;
    int n;

public:
    SimpleHashSet(int n)
    {
        this->set = new string[n];
        this->n = n;
    }
    void insertInSet(string name)
    {
        int asciiSum = 0;
        for (char c : name)
            asciiSum += (int)c;
        int idx = asciiSum % this->n;
        set[idx] = name;
    }

    bool isThere(string name)
    {
        int asciiSum = 0;
        for (char c : name)
            asciiSum += (int)c;
        int idx = asciiSum % this->n;
        return this->set[idx] == name;
    }

    void printSet()
    {
        for (int i = 0; i < this->n; i++)
            cout << this->set[i] << " ";
        cout << endl;
        return;
    }
};

void test() {
    int arr[5] ;
    for(auto &a : arr) cin >> a ;
    for(auto &a : arr) cout << a << " " ;
}

int main()
{

    SimpleHashSet mySet(11);

    mySet.insertInSet("Mia");
    mySet.insertInSet("Tim");
    mySet.insertInSet("Bea");
    mySet.insertInSet("Zoe");
    mySet.insertInSet("Jan");
    mySet.insertInSet("Ada");
    mySet.insertInSet("Leo");
    mySet.insertInSet("Sam");
    mySet.insertInSet("Lou");
    mySet.insertInSet("Max");
    mySet.insertInSet("Ted");

    mySet.isThere("Max") ? cout << "Max is there in the set" : cout << "Max is not there in the set";
    cout << endl;
    mySet.isThere("Bed") ? cout << "Bed is there in the set" : cout << "Bed is not there in the set";
    cout << endl;
    mySet.printSet();

    test() ;

    return 0;
}