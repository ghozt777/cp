// link : https://leetcode.com/problems/unique-binary-search-trees/

// total number of unique BSTs with 1 -> n nodes = catalan(n)
// link to Catalan Numbers : https://en.wikipedia.org/wiki/Catalan_number/

class Solution {
long CalculateCoeff(int n,int k) //Function to calculate Ci(n.k)
    {
        long res=1;
        if(k>n-k)
            k=n-k;                    //Since Ci(n,k)=Ci(n,n-k), property of binomial coefficients
        for(int i=0;i<k;i++)
        {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    int catalan(int n){
     return CalculateCoeff(2*n,n)/(n+1);   
    }
public:
    int numTrees(int n) {
        return catalan(n) ;
    }
};