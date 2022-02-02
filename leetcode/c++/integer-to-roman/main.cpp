// link : https://leetcode.com/problems/integer-to-roman/

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

string intToRoman(int num)
{
    // use greedy approach :
    string ans("");
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    while (num)
    {
        int q = num / val[i];       // total count of the particular character
        int r = num % val[i];       // new num value to be updated
        for (int k = 0; k < q; k++) // run the loop for total number of current character
            ans += sym[i];
        ++i;
        num = r;
    }
    return ans;
}

void Run()
{
    int n;
    cin >> n;
    cout << intToRoman(n) << endl;
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