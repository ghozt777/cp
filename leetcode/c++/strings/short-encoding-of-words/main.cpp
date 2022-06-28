// link : https://leetcode.com/problems/short-encoding-of-words/
// https://leetcode.com/problems/short-encoding-of-words/discuss/125811/C%2B%2BJavaPython-Easy-Understood-Solution-with-Explanation
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(),words.end()) ;
        for(string x :s){
            for(int i=1;i<x.length();i++) s.erase(x.substr(i)) ;
        }
        int res=0;
        for(string x:s) res+=x.length()+1;
        return res;
    }
};


/*

Deacription analyse
Let’s get the deacription clear:
Given string list L1, construct a another string list L2, making every word in L1 be a suffix of a word in L2.
Return the minimum possible total length of words in L2
Input L1: [“time”,“me”,“bell”]
L2: [“time”,“bell”]

Explanation of solution
Base on @awice's idea. This solution is not my intuition but it is really simple to write, compared with Trie solution.

Build a set of words.
Iterate on all words and remove all suffixes of every word from the set.
Finally the set will the set of all encoding words.
Iterate on the set and return sum(word's length + 1 for every word in the set)
Complexity
O(NK^2) for time and 'O(NK)' for space.
It is really kind of K with K <= 7, almost ignorable.
I should have suggested for bigger 'K' cases.
I believe it will take more time for most people to solve this problem if we have a big K.

*/