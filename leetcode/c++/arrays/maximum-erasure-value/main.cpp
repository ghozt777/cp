// link : https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0 ;
        int res = 0 ;
        set<int> seen ;
        int start = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(seen.find(nums[i]) == seen.end()){
                sum += nums[i] ;
                res = max(res , sum) ;
                seen.insert(nums[i]) ;
            }
            else{
                seen.erase(nums[start]) ;
                sum -= nums[start++] ;
                --i ;
            }
        }
        return res ;
    }
};