#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int zeroCount = 0;
    int zero_pos = -1;
    int total_product = 1;
    int n = nums.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            ++zeroCount;
            zero_pos = i;
        }
        else
            total_product *= nums[i];
        if (zeroCount > 1)
            return ans;
    }
    if (zeroCount == 1)
    {
        ans[zero_pos] = total_product;
        return ans;
    }
    else
    {
        for (int i = 0; i < n; i++)
            ans[i] = total_product / nums[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> res = productExceptSelf(v);
    for (int x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}