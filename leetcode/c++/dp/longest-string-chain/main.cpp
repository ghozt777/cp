// linkhttps://leetcode.com/problems/longest-string-chain/

class Solution {
    static bool compareTwoStrungsBasedsOnLength(string & s1 , string & s2){
        return s1.length() < s2.length() ;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , compareTwoStrungsBasedsOnLength) ;
        map<string , int> dp ;
        for(string & w : words){
            for(int i = 0 ; i < w.length() ; i++){
                string pre = w.substr(0 , i) + w.substr(i + 1) ;
                if(dp.find(pre) != dp.end()) dp[w] = max(dp[w] , 1 + dp[pre]) ;
                else dp[w] = max(dp[w] , 1) ;
            }
        }
        int res = INT_MIN ;
        for(auto x : dp) res = max(res , x.second) ;
        return res ;
    }
};