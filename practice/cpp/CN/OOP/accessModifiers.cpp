#include <bits/stdc++.h>

using namespace std;

class myArray
{
private:
    int *arr;
    int n;

public:
    myArray(int n)
    {
        this->n = n;
        this->arr = new int[n];
    }

    void setArray()
    {
        cout << "Enter n : ";
        int n;
        cin >> n;
        if (n > this->n)
        {
            cout << "Error !" << endl;
            return;
        }
        for (int i = 0; i < n; i++)
            cin >> this->arr[i];
    }

    void printArray()
    {
        if (this->n == 0)
        {
            cout << "[]";
            return;
        }
        if (this->n == 1)
        {
            cout << "[" << this->arr[0] << "]";
            return;
        }
        cout << "[" << this->arr[0] << ", ";
        for (int i = 1; i < this->n - 1; i++)
            cout << this->arr[i] << ", ";
        cout << this->arr[n - 1] << "]";
        cout << endl ;
    }
};

int main()
{
    myArray arr(10);
    arr.setArray();
    arr.printArray();
    return 0;
}