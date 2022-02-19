// link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
    int findPivot(vector<int> &nums){
        if(!nums.size()) return -1 ;
        int start = 0 ;
        int end = nums.size() - 1 ;
        if(nums[start] <= nums[end]) return nums.size() - 1 ;
        while(start <= end){
            int mid = start + (end - start) / 2 ;
            if(mid < end && nums[mid] > nums[mid + 1]) return mid ;
            else if(mid > start && nums[mid - 1] > nums[mid]) return mid - 1;
            else if(nums[start] <= nums[mid]) start = mid + 1 ;
            else end = mid - 1 ; 
        }
        return -1 ;
    }
public:
    int findMin(vector<int>& nums) {
        int pivot = findPivot(nums) ;
        return pivot == nums.size() - 1 ? nums[0] : nums[pivot + 1] ; 
    }
};