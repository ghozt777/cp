// link:https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

// class Solution {
//     int f(string &s){
//         sort(s.begin(),s.end());
//         map<char,int> m;
//         for(char x:s)++m[x];
//         return m[s[0]];
//     }
// public:
//     vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
//         vector<int> fx;
//         vector<int> res;
//         for(auto x:words) fx.push_back(f(x));
//         sort(fx.begin(),fx.end());
//         for(auto x:queries){
//             int target=f(x);
//             int start=0;
//             int end=fx.size();
//             while(start<end){
//                 int mid=start+(end-start)/2;
//                 if(fx[mid]<=target)start=mid+1;
//                 else end=mid;
//             }
//             res.push_back(fx.size()-end);
//         }
//         return res;
//     }
// };

// a bit optimized
class Solution {
    int f(string &s){
        char _min='z';
        for(auto x:s)_min=min(_min,x);
        return count(s.begin(),s.end(),_min);
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        const int n=words.size();
        const int m=queries.size();
        vector<int> fx(n);
        vector<int> res(m);
        for(int i=0;i<n;i++) fx[i]=f(words[i]);
        sort(fx.begin(),fx.end());
        for(int i=0;i<m;i++){
            int target=f(queries[i]);
            int start=0;
            int end=fx.size();
            while(start<end){
                int mid=start+(end-start)/2;
                if(fx[mid]<=target)start=mid+1;
                else end=mid;
            }
            res[i]=fx.size()-end;
        }
        return res;
    }
};