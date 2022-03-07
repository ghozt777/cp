// link : https://leetcode.com/problems/k-closest-points-to-origin/submissions/

class Solution
{
    double getDistance(int x, int y)
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int n)
    {
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto k : points)
        {
            int x = k[0];
            int y = k[1];
            double dist = getDistance(x, y);
            pq.push(make_pair(dist, make_pair(x, y)));
            if (pq.size() > n)
                pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty())
        {
            vector<int> line(2);
            pair<double, pair<int, int>> top = pq.top();
            pq.pop();
            line[0] = top.second.first;
            line[1] = top.second.second;
            res.push_back(line);
        }
        return res;
    }
};
