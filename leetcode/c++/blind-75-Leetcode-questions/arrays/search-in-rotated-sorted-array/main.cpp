// link : https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
    
public:
int search(vector<int> & arr , int target){
  int pivot = findPivot(arr) ;
  int ans ;
  ans = binarySearch(arr , 0 , pivot , target) ;
  if(ans != -1) return ans ;
  ans = binarySearch(arr , pivot + 1 , arr.size() - 1  , target) ;
  return ans;
}

int binarySearch(vector<int> & arr , int start , int end , int target){
  if(start > end) return -1 ;
  int mid = start + (end - start) / 2 ;
  if(arr.at(mid) == target) return mid ;
  else if(arr.at(mid) < target) return binarySearch(arr , mid + 1 , end , target) ;
  else return binarySearch(arr , start , mid - 1 , target) ;
}

int findPivot(vector<int> & arr){
  int start = 0 ; 
  int end = arr.size() - 1 ;
  while(start < end){
    int mid = start + (end - start) / 2 ;
    if(mid < end && arr[mid] > arr[mid + 1]) return mid ;
    else if(mid > start && arr[mid - 1] > arr[mid]) return mid - 1 ;
    else if(arr[start] <= arr[mid]) start = mid + 1 ;
    else end = mid ;
  }
  return arr.size() - 1 ;
}
};