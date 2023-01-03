// link: https://leetcode.com/problems/single-threaded-cpu/
// IDEA: Shortest Job First (SJF) Algorithm

class Solution {
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if(a.first != b.first) return a.first > b.first ;
        else return a.second > b.second ;
    }
};
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        using ll = long long ;
        vector<int> res;
        vector<vector<ll>> t ; 
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , myComp> pq ;
        for(ll i = 0 ; i < tasks.size() ; i++) t.push_back({tasks[i][0],tasks[i][1],i});
        sort(t.begin(),t.end(),[](const auto &a,const auto &b){
            if(a[0] != b[0]) return a[0] < b[0];
            else if(a[1] != b[1]) return a[1] < b[1] ;
            else return a[2] < b[2] ;
        });
        ll currTime = t[0][0] , start = 0;
        while(!pq.empty() || start < t.size()){
            while(start < t.size() && t[start][0] <= currTime){
                pq.push({t[start][1],t[start][2]});
                ++start;
            }
            if(!pq.empty()){
                const auto currTask = pq.top();
                pq.pop();
                ll idx = currTask.second , processingTime = currTask.first ;
                res.push_back(idx);
                currTime += processingTime ;
            }
            else currTime = t[start][0];
        }
        return res ;
    }
};