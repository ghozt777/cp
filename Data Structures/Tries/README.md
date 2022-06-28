### Tries
Tries also known as Prefix Trees are <b>Rooted Trees</b>
- Structude of a Trie can resemble something like this: 
```c++
/*
    `data` stores the value of the Trie Node
    `child` points to its children
    `end` signifies does a word end here
*/
class TrieNode{
    char data;
    vector<TrieNode*>child(26,NULL);
    bool end;
};
```





