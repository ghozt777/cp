// link: https://leetcode.com/problems/edit-distance/

class Solution {
    vector<vector<int>> dp ;
    int brute_force(string &w1,string &w2,int i = 0 , int j = 0){
        if(i == w1.length() || j == w2.length()) return max({(int)(w1.length() - i),(int)(w2.length() - j)});
        if(dp[i][j] != INT_MAX) return dp[i][j] ;
        if(w1[i] == w2[j]) return brute_force(w1,w2,i + 1,j + 1);
        int r = INT_MAX ;
        r = min(r,brute_force(w1,w2,i + 1,j)); // delete word from w1
        r = min(r,brute_force(w1,w2,i,j + 1)); // insert word in w1
        r = min(r,brute_force(w1,w2,i + 1,j + 1)); // replace word in w1 ;
        return dp[i][j] = r + 1 ;
    }
public:
    int minDistance(string word1, string word2) {
        dp.resize(word1.length() , vector<int>(word2.length() , INT_MAX));
        return brute_force(word1,word2);
    }
};