// link : https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push(make_pair(nums[i], i));
        vector<int> idx, res;
        while (k--)
            idx.emplace_back(pq.top().second), pq.pop();
        sort(idx.begin(), idx.end());
        for (int i : idx)
            res.emplace_back(nums[i]);
        return res;
    }
};