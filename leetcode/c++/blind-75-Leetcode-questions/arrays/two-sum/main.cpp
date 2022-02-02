// link : https://leetcode.com/problems/two-sum/ 
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);
    unordered_map<int, int> ht;
    for (int i = 0; i < nums.size(); i++)
    {
        unordered_map<int, int>::iterator it = ht.find(target - nums[i]);
        if (it != ht.end())
        {
            ans[0] = it->second;
            ans[1] = i;
            return ans;
        }
        else
            ht.insert(make_pair(nums[i], i));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int target;
    cin >> target;
    vector<int> ans = twoSum(v, target);
    cout << "[" << ans[0] << "," << ans[1] << "]" << endl;
    return 0;
}