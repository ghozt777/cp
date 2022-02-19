// link : https://leetcode.com/problems/container-with-most-water/

/*
    IDEA : 
    Use two pointer method and at each step compute the max area by formula distnace_between * min(height of the two pilars) 
    After that move past the smaller of the two pillars
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0 ;
        int end = height.size() - 1 ;
        int res = 0 ;
        while(start < end){
            res = max(res , (end - start) * min(height[start] , height[end])) ;
            if(height[start] <= height[end]) ++start ;
            else --end ;
        }
        return res ;
    }
};