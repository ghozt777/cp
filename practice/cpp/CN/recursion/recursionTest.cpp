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

bool util(int *arr, int n, int left, int right)
{
    if (n == 0)
        return left == right;

    if (arr[0] % 5 == 0)
        left += arr[0];
    else if (arr[0] % 3 == 0)
        right += arr[0];
    else
        return util(arr + 1, n - 1, left + arr[0], right) || util(arr + 1, n - 1, left, right + arr[0]);
    return util(arr + 1, n - 1, left, right);
}

bool splitArray(int *arr, int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return util(arr, n, 0, 0);
}

int myMax(int a, int b)
{
    return a >= b ? a : b;
}

int util(int b[], int n)
{
    if (n == 1)
        return b[0];
    return myMax(n * b[0], util(b + 1, n - 1));
}

int maximumProfit(int budget[], int n)
{
    // Write your code here
    sort(budget, budget + n);
    return util(budget, n);
}

bool checksequenece(char large[], char *small)
{
    if (large[0] == '\0' && small[0] != '\0')
        return false;
    if (small[0] == '\0')
        return true;
    int i = 0;
    while (large[i] != small[0])
    {
        if (large[i] == '\0')
            return false;
        ++i;
    }
    return checksequenece(large + i + 1, small + 1);
}

void Run()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
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