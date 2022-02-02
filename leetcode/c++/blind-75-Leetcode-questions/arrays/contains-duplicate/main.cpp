#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> check;
    for (int i = 0; i < nums.size(); i++)
    {
        if (check.find(nums[i]) != check.end())
            return true;
        else
            check.insert(nums[i]);
    }
    return false;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> v(n , 0) ;
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
    containsDuplicate(v) ? cout << "true" << endl : cout << "false" << endl ;
    return 0;
}