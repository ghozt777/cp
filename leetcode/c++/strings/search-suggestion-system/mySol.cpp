// link : https://leetcode.com/problems/search-suggestions-system/
// video explaination: https://www.youtube.com/watch?v=D4T2N0yAr20

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int left=0;
        int right=products.size()-1;
        vector<vector<string>> res ;
        
        for(int i=0;i<searchWord.length();i++){
            char x=searchWord[i];
            while(left<=right && (products[left].length() <=i || products[left][i] != x)) ++left ;
            while(left<=right && (products[right].length() <=i || products[right][i] != x)) --right ;
            
            vector<string> toAdd ;
            for(int count=0;count<min(right-left+1,3);count++){
                toAdd.push_back(products[left+count]);
            }
            res.push_back(toAdd) ;
        }
        return res ;
    }
};