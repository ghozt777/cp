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

void util(int ip[], int n, int op[], int m)
{
    if (n == 0)
    {
        for (int i = 0; i < m; i++)
            cout << op[i] << " ";
        cout << endl;
        return;
    }
    util(ip + 1, n - 1, op, m);
    op[m] = ip[0];
    util(ip + 1, n - 1, op, m + 1);
}

void printSubsetsOfArray(int ip[], int n)
{
    // Write your code here
    int *op = new int[1000];
    util(ip, n, op, 0);
}

void Run()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);

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