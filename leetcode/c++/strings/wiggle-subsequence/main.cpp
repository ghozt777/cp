// link: https://leetcode.com/problems/wiggle-subsequence/

class Solution {
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        string diff="";
        char curr;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) curr='+';
            else if(nums[i]<nums[i-1]) curr='-';
            else curr='0';
            if(curr!='0' && (!diff.length()||curr!=diff[diff.length()-1])) diff+=curr;
        }
        return diff.length()+1;
    }
};