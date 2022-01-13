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

int subsetSumToK(int ip[], int n, int op[][50], int k)
{
    // Write your code here
    if (n == 0)
    {
        if (k == 0)
        {
            op[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }

    int c1 = subsetSumToK(ip + 1, n - 1, op, k);
    int c2 = subsetSumToK(ip + 1, n - 1, op + c1, k - ip[0]);
    int c = c1 + c2;
    for (int i = c1; i < c; i++)
    {
        for (int j = op[i][0]; j > 0; j--)
            op[i][j + 1] = op[i][j];
        op[i][0]++;
        op[i][1] = ip[0];
    }
    return c;
}

void Run()
{

    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
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