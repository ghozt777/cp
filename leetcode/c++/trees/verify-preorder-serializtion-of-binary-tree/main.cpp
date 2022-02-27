// link : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
/*
    IDEA :
    In preorder traversal we initialize the number os slots to be 1 for the root
    slots represnt vacant position for nodes to be entered
    if we encounter a ',' we simply continue
    else if we encounter a '#' -> represents the end of a branch : Now total numbe of nodes branching from this node = 0 , also it occupies 1 space to store(we store NUUL here) hence net effect on number of slots : (0 - 1) = -1
    else we found a legit node -> total number of nodes branching from a legit node = 2 , also it takes 1 space to store the root , hence net effect on the total number of slots = (2 - 1) = 1

    during processing we find the toal number of node = 0 , i.e. there are no vacant positions left for the rest of the nodes -> hence the serialization of wrong
    also ideally after processing all the nodes the remaing number of slots left muts be 0 if not then the serialization is wrong
*/

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int slots = 1;
        for (int i = 0; i < preorder.size(); i++)
        {
            if (slots <= 0)
                return false;
            if (preorder[i] == ',')
                continue;
            else if (preorder[i] == '#')
                slots += -1;
            else
            {
                while (i < preorder.size() && preorder[i] != ',')
                    ++i;
                slots += 1;
            }
        }
        return slots == 0;
    }
};