// link : https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map ;
        stack<int> s ;
        vector<int> aux(nums2.size()) ;
        for(int i = nums2.size() - 1 ; i >=0 ; --i){
            map[nums2[i]] = i ;
            if(s.empty()) aux[i] = -1 ;
            else{
                if(s.top() > nums2[i]) aux[i] = s.top() ;
                else{
                    while(s.top() < nums2[i]){
                        s.pop() ;
                        if(s.empty()) break ;
                    }
                    aux[i] = s.empty() ? -1 : s.top() ;
                }
            }
            s.push(nums2[i]) ;
        }
        vector<int> res(nums1.size()) ;
        for(int i = 0 ; i < nums1.size() ; i++){
            res[i] = aux[map[nums1[i]]] ;
        }
        return res ;
    }
};