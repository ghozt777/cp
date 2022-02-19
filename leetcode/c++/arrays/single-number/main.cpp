// link : https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> _map ;
        for(int x: nums) _map[x]++ ;
        for(auto x : _map) if(x.second == 1) return x.first ;
        return -1 ;
    }
};