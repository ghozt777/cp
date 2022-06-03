// link : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/submissions/

/*
    Approach(DP / Greedy);
    Since given array is the inorder traversal of tree leaves. Their order won't change. You can only decide which 2 consecutive nodes you wanna combine to make a new node by their product.

Suppose array is [8,4,1,2,5]
You can multiply two consecutive digits and their product will be added to resultant sum. And those 2 digits will be replaced my max of them.
Ex-

initial:
arr=8,4,1,2,5
sum-0;

iteration-1:
multiply 1,2
arr = 8,4,2,5 ( because 2>1)
and sum=2;

iteration-2:
multiply 4,2
arr= 8,4,5 (because 4>2)
and sum=2+8=10;

iteration-3:
multiply 4,5
arr= 8,5 (because 5>4)
and sum= 10+ 20 = 30;

iteration-4:
multiply 8,5
sum=30+40

Answer is 70.
*/

class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int sum = 0;
        while (arr.size() > 1)
        {
            int _min_index = -1;
            int _min = INT_MAX;
            for (int i = 0; i < arr.size() - 1; i++)
                if (arr[i] * arr[i + 1] < _min)
                {
                    _min = arr[i] * arr[i + 1];
                    _min_index = arr[i] < arr[i + 1] ? i : i + 1;
                }
            arr.erase(arr.begin() + _min_index);
            sum += _min;
        }
        return sum;
    }
};