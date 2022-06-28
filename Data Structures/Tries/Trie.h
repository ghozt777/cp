#include<vector>
class TrieNode {
    char data;
    std::vector<TrieNode*> child;
    bool end;
public:
    TrieNode() {
        this->child.clear();
        this->child.resize(26, nullptr);
    }
    TrieNode(char data) {
        TrieNode();
        this->data = data;
    }
    TrieNode(bool end) {
        TrieNode();
        this->end = end;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode(false);
    }

};

