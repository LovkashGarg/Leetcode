class TrieNode {
      public:
      char data;
      TrieNode *children[26];
      bool isTerminal;

      TrieNode (char c){
        data=c;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
      }
    
};
class Trie {
public:
TrieNode *root;
    Trie() {
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode *root,string word ){
        if(word.length()==0){
            // make this node the last node 
            root->isTerminal=true;
            return;
        }
     int index=word[0]-'a';
     TrieNode *child;
     if(root->children[index]!=nullptr){
        child=root->children[index];
     }
     else{
        child=new TrieNode(word[0]);
        root->children[index]=child;
     }
     insertUtil(child,word.substr(1));

    }
    void insert(string word) {
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode *root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'a';
        TrieNode *child=root->children[index];
        if(child!=nullptr){
            return searchUtil(child,word.substr(1));
        }
        return false;
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
    bool startsWithUtil(TrieNode *root,string prefix){
        if(prefix.length()==0){
            return true;
        }
        int index=prefix[0]-'a';
        if(root->children[index]!=nullptr){
            return startsWithUtil(root->children[index],prefix.substr(1));
        }
        else{
            return false;
        }
    }
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */