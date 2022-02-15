// link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std ;

int lengthOfLongestSubstring(string s) {
        unordered_set<char> hs;
        int start = 0 ;
        int end = 0 ;
        int ans = 0 ;
        while(end < s.size()){
            if(hs.find(s[end]) == hs.end()){
                hs.insert(s[end++]) ;
                if(hs.size() > ans) ans = int(hs.size()) ;
            }
            else hs.erase(s[start++]) ;
        }
        return ans;
    }

int main() {
    cout << lengthOfLongestSubstring("abcddcsda") << endl ;
    return 0 ;
}
