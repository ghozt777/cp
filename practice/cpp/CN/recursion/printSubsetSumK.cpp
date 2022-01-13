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

void util(int ip[], int n, int k, vector<int> op)
{
    if (n == 0)
    {
        if (k == 0)
        {
            for (int x : op)
                cout << x << " ";
            cout << endl;
            return;
        }
        else
            return;
    }
    util(ip + 1,n - 1,k,op) ;
    op.push_back(ip[0]);
    util(ip + 1,n - 1,k - ip[0],op) ;
}

void printSubsetSumToK(int input[], int size, int k)
{
    // Write your code here
    vector<int> op;
    util(input, size, k, op);
}

void Run()
{

    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
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