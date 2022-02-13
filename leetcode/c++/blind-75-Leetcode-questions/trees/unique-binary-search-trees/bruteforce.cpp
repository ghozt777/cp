// this gives a TLE Do not use : (answer is correct) 
// to avoid TLE use Catalan Number(n)
// Catalan Number Wikipedia : https://en.wikipedia.org/wiki/Catalan_number
class Solution {
    int util(int start , int end){
        if(start > end) return 1 ;
        int ans = 0 ;
        for(int i = start ; i <= end ; i++){
            int left = util(start , i - 1) ;
            int right = util(i + 1 , end) ;
            ans += left*right ;
        }
        return ans ;
    }
public:
    int numTrees(int n) {
        if(n == 0) return 0 ;
        return util(1 , n) ;
    }
};