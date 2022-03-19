// link : https://leetcode.com/problems/3sum-closest/
// approach used : Two Pointers O(n^2)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end()) ;
        int res = 0 ;
        int minDiff = INT_MAX ;
        for(int i = 0 ; i < nums.size() ; i++){
            int start = i + 1 ;
            int end = nums.size() - 1 ;
            while(start < end){
                int possibleAns = nums[i] + nums[start] + nums[end] ;
                if(possibleAns == target) return possibleAns ;
                if(abs(target - possibleAns) < minDiff){
                    minDiff = abs(target - possibleAns) ;
                    res = possibleAns ;
                }
                if(possibleAns < target) ++start ;
                else --end ;
            }
        }
        return res ;
    }
};