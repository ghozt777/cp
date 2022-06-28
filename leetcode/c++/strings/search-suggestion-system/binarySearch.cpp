// Link : https://leetcode.com/problems/search-suggestions-system/

// V1
class Solution {
public:
        vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur)) break; // max limit 
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};


// V2
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int left = 0, right = products.size() - 1;
        for (int i = 0; i < searchWord.length(); i++) {
            vector<string> res;
            char c = searchWord[i];
            while (left <= right && (products[left].length() == i || products[left][i] < c)) left++;
            while (left <= right && (products[right].length() == i || products[right][i] > c)) right--;
            for (int j = 0; j < 3 && left + j <= right; j++)
                res.push_back(products[left+j]);
            ans.push_back(res);
        }
        return ans;
    }
};