//link: https://leetcode.com/problems/find-and-replace-pattern/submissions/

class Solution {
    bool check(string &s1,string &s2){
        if(s1.length()!=s2.length()) return false;
        map<char,char> m;
        set <char>s;
        for(int i=0;i<s1.length();i++){
            if(m.find(s1[i])==m.end()){
                if(s.find(s2[i])!=s.end()) return false;
                s.insert(s2[i]);
                m[s1[i]]=s2[i];
            }
            else if(m[s1[i]]!=s2[i])return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto x:words) if(check(x,pattern)) res.push_back(x);
        return res;
    }
};