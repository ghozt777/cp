//link: https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp(n);
        int curr=n-1;
        int i=1;
        while(i<n){
            temp[i]=nums[curr--];
            i+=2;
        }
        i=0;
        while(i<n){
            temp[i]=nums[curr--];
            i+=2;
        }
        for(int k=0;k<n;k++) nums[k]=temp[k];
    }
};