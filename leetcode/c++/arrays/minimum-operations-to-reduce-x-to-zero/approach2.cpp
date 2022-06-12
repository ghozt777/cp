// link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/submissions/
// faster than approach 1

/*
    Approach 2: longest subarray have sum == sum(nums) - x
    - Idea: If u find longest subarray have sum == sum(nums) - x 
        => minimun operation = nums.size() - size(longest subarray)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin() , nums.end() , 0) ;
        if(x > totalSum) return -1 ;
        if(x == totalSum) return nums.size() ;
        
        int currSum = 0 , start = 0 , n = nums.size() , i = 0 , target = totalSum - x , maxLength = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            currSum += nums[i] ;
            while(currSum > target) currSum -= nums[start++] ;
            if(currSum == target) maxLength = max(maxLength , i - start + 1) ;
        }
        return maxLength == 0 ? -1 : n - maxLength ;
    }
};