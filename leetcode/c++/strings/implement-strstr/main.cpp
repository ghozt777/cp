// link: https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int l=needle.length();
        const int n=haystack.length();
        for(int end=l-1,start=0;end<n;end++,++start){
            if(haystack.substr(start,end-start+1)==needle) return start;
        }
        return -1;
    }
};