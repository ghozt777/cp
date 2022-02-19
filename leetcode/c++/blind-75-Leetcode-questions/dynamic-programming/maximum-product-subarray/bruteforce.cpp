// link : https://leetcode.com/problems/maximum-product-subarray/
// WILL GIVE A TLE

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN ;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                if(i <= j){
                    int curr = 1 ;
                    for(int k = i ; k <= j ; k++) curr *= nums[k] ;
                    res = max(res , curr) ;
                }
            }
        }
        return res ;
    }
};