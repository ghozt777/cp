// link : https://leetcode.com/problems/3sum/

/*
    IDEA : 
    Sort the array and then : 
    we need to find a , b , c such that a + b + c = 0 or a = - (b + c) 
    so we runa loop for a and find -(b + c) using two pointers 
    also skip duplicates at each level to avoid same answer with different aggagement of elements
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res ;
        if(nums.size() < 3) return res ;
        sort(nums.begin() , nums.end()) ;
        for(int i = 0 ; i < nums.size(); i++){
            int start = i + 1 ;
            int end = nums.size() - 1 ;
            while(start < end){
                int sum = nums[start] + nums[end] ;
                if(sum == 0 - nums[i]){
                    vector<int> ans = {nums[i] , nums[start] , nums[end]} ;
                    res.push_back(ans) ;
                    while(start < end && nums[start] == nums[start + 1]) ++start ; // avoid duplicates
                    while(start < end && nums[end] == nums[end - 1]) --end ; // avoid duplicates
                    ++start ;
                    --end ;
                }
                else if(sum < 0 - nums[i]){
                    while(start < end && nums[start] == nums[start + 1]) ++start ; // avoid duplicates
                    ++start ;
                }
                else{
                    while(start < end && nums[end] == nums[end - 1]) --end ; // avoid duplicates
                    --end ;
                }
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i ; // avoid duplicates
        }
        return res ;
    }
};