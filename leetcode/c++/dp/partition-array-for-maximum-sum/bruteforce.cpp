// link : https://leetcode.com/problems/partition-array-for-maximum-sum/
// This solution will not work use DP insted 

class Solution {
    int maxSumAfterPartitioning(vector<int> &arr , int k , int i){
        static const int n = arr.size() ;
        long long currMax = 0 ;
        long long currAns = 0 ;
        // starting from i we can chhose a max length of k 
        for(int j = 0 ; j < k ; j++){
            int to = i + j ;
            if(to >= n) break ;
            currMax = max(currMax , (long long)arr[to]) ;
            int leftSum = (to - i + 1) * (int)currMax ;
            int rightSum = maxSumAfterPartitioning(arr , k , to + 1) ;
            currAns = max((int)currAns , (leftSum + rightSum)) ;
        }
        return currAns ;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        if(arr.size() == 0) return 0 ;
        return maxSumAfterPartitioning(arr , k , 0) ;
    }
    
};