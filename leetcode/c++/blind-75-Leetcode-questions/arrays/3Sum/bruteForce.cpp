// leetcode link : https://leetcode.com/problems/3sum/
// article link : https://www.tutorialcup.com/leetcode-solutions/3sum-leetcode-solution.htm

/*
    Approach 1 (Brute Force + Binary Search)
    we need to find unique triplets with a+b+c =0, let’s say we know the value of a and b, using the equation( a+b+c =0 ) we can find the value of c, which is -(a+b).

    if we take all the possible (a,b) pairs, we can get all pairs of a,b using 2 nested for loops. after that, we can use binary search to know if c=-(a+b) exists in the given array or not.
    if it exists then the triplet (a,b,-(a+b)) will be a possible triplet. in this way, we will get all the possible triplets with a+b+c=0, but we need to find the unique triplets,
    for that we can insert all these possible triplets in some data structure( i.e. set) to get unique triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;//to get unique triplets
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp;
        temp.resize(3);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(binary_search(nums.begin()+j+1,nums.end(),-nums[i]-nums[j])){
                     temp[0]=nums[i],temp[1]=nums[j],temp[2]=-nums[i]-nums[j];
                    sort(temp.begin(),temp.end());
                    //to get triplet in an order, will be easy to check if 
                    //duplicate exists or not
                    s.insert(temp);
                    }
            }
        vector<vector<int>> ans;
        for(auto triplet: s)
            ans.push_back(triplet);
        return ans;
    }
    
};