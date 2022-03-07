// link : https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> hm;
        priority_queue<pair<int , int> , vector<pair<int, int>> , greater<pair<int , int>> > pq ;
        for(int x : nums) hm[x]++ ;
        for(auto x : hm){
            pq.push(make_pair(x.second , x.first)) ;
            if(pq.size() > k) pq.pop() ;
        }
        vector<int> res ;
        while(!pq.empty()){
            res.push_back(pq.top().second) ;
            pq.pop() ;
        }
        return res ;
    }
};