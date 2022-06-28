// link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string str) {
        map<char,int> m;
        for(char x:str) ++m[x];
        set<int> s;
        for(auto x:m){
            if(s.find(x.second)==s.end())s.insert(x.second);
            else{
                int check=x.second;
                while(check>0){
                    if(s.find(check)==s.end()){
                        s.insert(check);
                        break;
                    }
                    --check;
                }
            }
        }
        int sum=0;
        for(auto &x:s) sum+=x;
        return str.length()-sum;
    }
};