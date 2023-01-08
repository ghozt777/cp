// link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> t ;
        for(int x : tasks) ++t[x] ;
        int res = 0 ;
        for(auto x:t){
            int a = 0 , b = 0 ;
            if(x.second == 1) return -1 ;
            if(x.second % 3 == 0){
                a = x.second / 3 ;
            }
            else if(x.second % 3 == 1){
                b = 2 ;
                a = (x.second - 4) / 3 ;
            }
            else{
                b = 1 ;
                a = (x.second - 2) / 3 ;
            }
            res += (a + b) ;
        }
        
        return res;
    }
};