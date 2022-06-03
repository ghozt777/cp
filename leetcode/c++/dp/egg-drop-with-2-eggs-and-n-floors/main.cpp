// link : https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/submissions/

/*
    Approach to solution : 

    Suppose we are at a building with i levels
    
    now if we drop an egg(both eggs surviving at this point) then there are two possible cases : 
        a. the egg breaks so we are left with only one egg
        b. the egg survuves we have both of our eggs
        
        case a : 
        when the egg breaks at a level x we know that F lies between 1 <= F < x 
        so to determine F we can drop the last egg at each floor from 1 to x - 1 to check 
        so number of moves = 1 + (x - 1) ; 
                             ^      ^
                             |      |
                    to drop at x    to drop at each floor before x
                    
        case b :  
        the egg survives so we have 2 eggs with (i - x) levels to check 
        so this is a subproblem with (i - x) levels which we can use dp to store 
        
        the result at each (i , x) where i = total_number_of_floors and x = situation_where_we_drop_the_first_egg_from_x_floor
        res(i,x) = max((case a) , (case b)) : its max because me need to perform at least res(i,x) steps to be certain 
        
        also res(i) = min(for each x in 1 to i -> res(i,x)) ;
        
        at the end we return res[n] ;

*/

class Solution {
public:
    // using top down apprach 
    int twoEggDrop(int n) {
        // dp.resize(n + 1 , -1) ;
        if(n <= 2) return n ;
        vector<int> res(n + 1 , INT_MAX) ;
        
        res[0] = 0 ;
        res[1] = 1 ;
        res[2] = 2 ;
        
        
        for(int i = 3; i <= n ; i++){
            int resI = INT_MAX ;
            for(int j = 1 ; j <= i ; j++){
                int ifBreaks = 1 + j - 1 ;
                int ifSurvives = 1 + res[i - j] ;
                resI = min(resI , max(ifBreaks , ifSurvives));
            }
            res[i] = resI ;
        }
        
        return res[n] ;
        // return bruteforce(n) ;
    }
    
    // recurtsion with memoization
    
    vector<int> dp ;
    
    int bruteforce(int n){
        if(dp[n] != -1) return dp[n] ;
        if(n <= 2) return n ;
        int res = INT_MAX ;
        for(int x = 1 ; x <= n ; x++) res = min(res , max(1 + x - 1 , 1 + bruteforce(n - x))) ;
        return dp[n] = res ;
    }
};