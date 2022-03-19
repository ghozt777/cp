// link: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> hm ;
        for(string x : strs){
            string sortedString(x) ;
            sort(sortedString.begin() , sortedString.end()) ;
            hm[sortedString].push_back(x) ;
        }
        vector<vector<string>> res;
        for(auto x : hm) res.push_back(x.second) ;
        return res ;
    }
};