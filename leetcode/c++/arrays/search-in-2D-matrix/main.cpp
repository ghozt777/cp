// link : https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size() ;
        int m = arr[0].size() ;
        int start = 0 ;
        int end = n * m - 1 ;
        while(start <= end){
            int mid = start + (end - start) / 2 ;
            if(arr[mid / m][mid % m] == target) return true ;
            else if(arr[mid / m][mid % m] < target) start = mid + 1 ;
            else end = mid - 1 ;
        }
        return false; 
    }
};