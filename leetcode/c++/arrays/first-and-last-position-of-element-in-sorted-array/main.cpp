// link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
    int binarySearch(vector<int> & arr , int start , int end , int target){
        if(start > end) return -1 ;
        int mid = start + (end - start) / 2 ;
        if(arr[mid] == target) return mid ;
        else if(arr[mid] < target) return binarySearch(arr , mid + 1 , end , target) ;
        else return binarySearch(arr , start , mid - 1 , target) ;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1) ;
        int idx = binarySearch(nums , 0 , nums.size() - 1 , target) ;
        if(idx == -1) return ans ;
        int i = idx ;
        while(i > 0 && nums[i] == nums[i - 1]) --i;
        ans[0] = i ;
        i = idx ;
        while(i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i ;
        ans[1] = i ;
        return ans ;
    }
};