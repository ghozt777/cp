// link : https://leetcode.com/problems/partition-array-for-maximum-sum/
/*
    
    Approach : for each index i we can choose next k elements if it exists
               so in bruteforcing the solution we compute every possible senario for each i and update the ans
               In the solution `to` represents the ending index of the subarray and `from` represents the starting idex of the subarray
                
               dp[i] : represents the ans for the subproblem that ends at that index (or in other words arr starting from 0 to 1 -> a[0] ,  ... a[i])


        we keep track of the current max for all the possible partitions indices (from + 0)  ... (from + k - 1) (k - 1) as the current index also contributes to one element making the toal to k                               
        
        dp eqn : for each particular `to` value we compute possible `from` values and use the ans of the previously compute value to get the current value  
*/      

class Solution {
    int getMemoizedResult(int * dp , int i){
        if(i < 0) return 0 ;
        return dp[i] ;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        if(!arr.size()) return 0 ;
        const int n = arr.size() ;
        int dp[n] ;
        for(int i = 0 ; i < n ; i++){
            int to = i ;
            int currMax = INT_MIN ;
            int currAns = INT_MIN ;
            for(int j = 0 ; j < k ; j++){
                int from = to - j ;
                if(from < 0) break ;
                currMax = max(currMax , arr[from]) ;
                currAns = max(currAns , ((to - from + 1) * currMax + getMemoizedResult(dp , from - 1))) ;
                dp[i] = currAns ;
            }
        }
        return dp[n - 1] ;
    }
};