// link : https://leetcode.com/problems/maximum-score-from-removing-stones/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> piles ;
        piles.push(a) ;
        piles.push(b) ;
        piles.push(c) ;
        int res = 0 ;
        while(!piles.empty()){
            if(piles.size() < 2) break ;
            ++res ; 
            int p1 = piles.top() ;
            piles.pop() ;
            int p2 = piles.top() ;
            piles.pop() ;
            --p1 ;
            --p2 ;
            if(p1 > 0)piles.push(p1) ;
            if(p2 > 0)piles.push(p2) ;
        }
        return res ; 
    }
};