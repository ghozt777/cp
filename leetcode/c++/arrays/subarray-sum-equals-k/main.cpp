// link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0 ;
        unordered_map<int , int> m ;
        int res = 0 ;
        m[0] = 1 ;
        for(int x : nums){
            sum += x ;
            if(m[sum - k]) res += m[sum - k] ;
            ++m[sum] ;
        }
        return res ;
    }
};