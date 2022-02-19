// link : https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size() ;
        vector<int> _min(n) ;
        vector<int> _max(n) ;
        _min[0] = nums[0] ;
        _max[0] = nums[0] ;
        int res = INT_MIN ;
        for(int i = 1 ; i < n ; i++){
            _min[i] = min(_max[i-1]*nums[i] , min(_min[i -1]*nums[i] , nums[i])) ;
            _max[i] = max(_max[i-1]*nums[i] , max(_min[i -1]*nums[i] , nums[i])) ;
        }
        for(int x : _max) res = max(res , x) ;
        return res ;
    }
};