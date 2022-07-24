// link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        if(nums.size()%2==1){
            
            for(int x:nums) res+=abs(nums[nums.size()/2]-x);
        }
        else{
            int res1=0;
            int res2=0;
            for(int x:nums) res1+=abs(nums[nums.size()/2]-x) , res2+=abs(nums[(nums.size()-1)/2]-x);
            res=min(res1,res2);
        }
        return res;
    }
};