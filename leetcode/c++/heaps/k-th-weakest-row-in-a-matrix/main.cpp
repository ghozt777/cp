// link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < mat.size(); i++)
        {
            int c = 0;
            for (int x : mat[i])
                if (x)
                    ++c;
            pq.push(make_pair(c, i));
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(pq.top().second), pq.pop();
        return res;
    }
};