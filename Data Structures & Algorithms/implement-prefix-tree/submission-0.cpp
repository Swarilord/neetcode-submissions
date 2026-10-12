struct TrieNode{
    TrieNode* children[26] = {};
    bool end = false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
       root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        int reference;
        for(char c: word){
            reference = c - 'a';
            if(!curr -> children[reference]){
                curr -> children[reference] = new TrieNode();
            }
            curr = curr -> children[reference];
        }
        curr -> end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int ref;
        for(char c: word){
            ref = c - 'a';
            if(!curr -> children[ref]){
                return false;
            }
            curr = curr -> children[ref];
        }
        if(curr -> end == true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int ref;
        for(char c: prefix){
            ref = c - 'a';
            if(!curr -> children[ref]){
                return false;
            }
            curr = curr -> children[ref];
        }
        return true;
    }
};
