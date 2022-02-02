// link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
#include <unordered_set>

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

int ans(string str)
{
    if (str == "")
        return 0;
    unordered_set<char> s;
    int ans = 1;
    s.insert(str[0]);
    int i(0), j(0);
    ++j;
    while (j < str.length())
    {
        if (s.find(str[j]) == s.end())
        {
            s.insert(str[j]);
            ans = max(ans, j - (i - 1));
            ++j;
        }
        else
        {
            s.erase(str[i]);
            i++;
        }
    }
    return ans;
}

void Run()
{
    string test;
    cin >> test;
    cout << ans(test);

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