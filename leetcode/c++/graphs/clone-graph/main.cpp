// link: https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*,Node*> m;
    Node* dfs(Node*curr){
        if(!curr) return NULL ;
        if(m.find(curr)==m.end()){
            Node *clone=new Node(curr->val);
            m[curr]=clone ;
            for(auto x:curr->neighbors){
                clone->neighbors.push_back(dfs(x));
            }
        }
        return m[curr];
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};