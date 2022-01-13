#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;
typedef map<string, int> msi;

#define IN emplace
#define PBK pop_back
#define PB push_back
#define MP make_pair
#define f(n) for (int i = 0; i < n; i++)
#define fr(itr, n) for (int itr = 0; itr < n; itr++)

void Run();
void printArray(int[], int);
void test();

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    Run();
    return 0;
}

vector<char> getChars(int n)
{
    vector<char> v;
    pair<int *, int> chars;
    if (n < 7)
    {
        v.push_back(char(97 + (n - 2) * 3));
        v.push_back(char(97 + (n - 2) * 3 + 1));
        v.push_back(char(97 + (n - 2) * 3 + 2));
    }
    else if (n == 7)
    {
        v.push_back('p');
        v.push_back('q');
        v.push_back('r');
        v.push_back('s');
    }
    else if (n == 8)
    {
        v.push_back('t');
        v.push_back('u');
        v.push_back('v');
    }
    else
    {
        v.push_back('w');
        v.push_back('x');
        v.push_back('y');
        v.push_back('z');
    }
    return v;
}

void test()
{
    for (auto x : getChars(3))
        cout << x << " ";
    return;
}

void util(string n, string ans)
{
    if (n.empty())
    {
        cout << ans << endl;
        return;
    }
    int toProcess = n[0] - '0';
    vector<char> v = getChars(toProcess);
    for (int i = 0; i < v.size(); i++)
        util(n.substr(1), ans + v[i]);
}

void printKeypad(int num)
{
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    util(to_string(num), "");
}

void Run()
{
    int num;
    cin >> num;

    printKeypad(num);
    return;
}

void printArray(int arr[], int n)
{
    if (n == 0)
    {
        cout << "[]";
        return;
    }
    if (n == 1)
    {
        cout << "[" << arr[0] << "]";
        return;
    }
    cout << "[" << arr[0] << ", ";
    for (int i = 1; i < n - 1; i++)
        cout << arr[i] << ", ";
    cout << arr[n - 1] << "]";
}