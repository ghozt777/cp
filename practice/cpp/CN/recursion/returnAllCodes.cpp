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

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    Run();
    return 0;
}

int getInt(char c)
{
    return c - '0';
}

int util(string str, string op[10000], string p)
{
    if (str.empty())
    {
        op[0] = p;
        return 1;
    }
    int c1 = util(str.substr(1), op, p + (char)('a' + getInt(str[0]) - 1));
    int c2 = 0;
    if (str.length() >= 2 && (10 * getInt(str[0]) + getInt(str[1])) <= 26)
    {
        c2 = util(str.substr(2), op + c1, p + (char)('a' + (10 * getInt(str[0]) + getInt(str[1])) - 1));
    }
    return c1 + c2;
}

int getCodes(string input, string output[10000])
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    return util(input, output, "");
}

void Run()
{

    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
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