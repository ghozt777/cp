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

bool util(char ip[])
{
    if (ip[0] == '\0')
        return true;
    if (ip[0] == 'a')
    {
        if (ip[1] == '\0')
            return true;
        else if (ip[1] == 'a')
            return util(ip + 1);
        else if (ip[1] == 'b' && ip[2] == 'b')
        {
            if (ip[3] == '\0')
                return true;
            else if (ip[3] == 'a')
                return util(ip + 3);
            else
                return false;
        }
        else
            return false;
    }
    else if (ip[0] == 'b' && ip[1] == 'b')
    {
        if (ip[2] == '\0')
            return true;
        else if (ip[2] == 'a')
            return util(ip + 2);
    }
    else
        return false;

    return false;
}

bool checkAB(char ip[])
{
    // Write your code here
    if (ip[0] != 'a')
        return false;
    return util(ip + 1);
}

void Run()
{

    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
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