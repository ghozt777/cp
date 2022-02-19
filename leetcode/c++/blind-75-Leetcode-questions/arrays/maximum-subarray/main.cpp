// link : https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 ;
        int res = INT_MIN ;
        for(int x : nums){
            sum += x ;
            res = max(res , sum) ;
            if(sum < 0) sum = 0 ;
        }
        return res ; 
    }
};