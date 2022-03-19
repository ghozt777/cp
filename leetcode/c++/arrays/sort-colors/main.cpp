// link : https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dnf sort
        int start = 0 ;
        int curr = 0 ;
        int end = nums.size() - 1 ;
        while(curr <= end){
            if(nums[curr] == 1) ++curr ;
            else if(nums[curr] == 0) swap(nums[curr++] , nums[start++]) ;
            else swap(nums[curr] , nums[end--]) ;
        }
    }
};