//link: https://leetcode.com/problems/word-subsets/

class Solution {
    bool check(string &s1,map<char,int>&w2){
        map<char,int> w1;
        for(auto x:s1)++w1[x];
        for(auto &x:w2){
            if(w1.find(x.first)==w1.end())return false;
            else if(w1[x.first]<x.second)return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>m;
        for(string &s:words2){
            map<char,int> temp;
            for(char x:s)++temp[x];
            for(auto &x:temp){
                if(m.find(x.first)==m.end())m[x.first]=x.second;
                else m[x.first]=max(m[x.first]r,x.second);
            }
        }
        vector<string> res;
        for(auto &x:words1){
            if(check(x,m))res.push_back(x);
        }
        return res;
    }
};