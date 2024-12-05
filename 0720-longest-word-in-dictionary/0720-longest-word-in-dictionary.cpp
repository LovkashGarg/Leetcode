class TrieNode {
    public:
    char data;
    TrieNode *children[26];
    bool isWord;
    TrieNode(char c){
        data=c;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isWord=false;
    }

};
class Trie{
    public:
    TrieNode *root;
    Trie(){
        root=new TrieNode('\0');
        root->isWord=true;
    }
    void insertUtil(TrieNode * root, string w){
        if(w.length()==0){
            root->isWord=true;
            return ;
        }
        int index=w[0]-'a';

        TrieNode *child;
        if(root->children[index]!=nullptr){
            child=root->children[index];
          
        }
        else{
            child=new TrieNode(w[0]);
            root->children[index]=child;
        }
        insertUtil(child,w.substr(1));
    }
    void insertWord(string w){
      insertUtil(root,w);
    }
};

class Solution {
public:
string ans;
    void dfs(TrieNode *root,string temp){
        // I can go 26 zones
        // tell first if the current is Word or not 
        bool word=root->isWord;
       
        for(int i=0;i<26;i++){
             if(root->children[i]){
                if(root->children[i]->isWord==true && word==true){
                      temp.push_back(root->children[i]->data);
                    if(ans.size() <=temp.size()){
                        if(ans.size() == temp.size()){
                            // assign a shorter string 
                            ans = (ans >temp ? temp: ans);
                        }
                        else{
                        ans=temp;
                        }
                    }
                 dfs(root->children[i],temp);
                    temp.pop_back();
                }
             }
        } 

        // if(temp.size()>=1){
        // temp.pop_back();
        // }

    }
    string longestWord(vector<string>& words) {
        


        // I have to find the longest  word  which is formed by some other word 
        // For each I inserted I have one isWord I have to update the answer if the parent is also a word 


        // I have to traversal to each letter word 
        Trie *t=new Trie();
        int n=words.size();
        for(int i=0;i<n;i++){
          t->insertWord(words[i]);
        }

       // do a dfsTraversal to each word 
       string temp;
       dfs(t->root,temp);
    //    if(ans.size()==0){
    //      for(int i=0;i<n;i++){
    //         // since single character is also a word
    //         if(words[i].size()==1){
    //          ans=words[i];
    //         }
    //      }
    //    }

        return ans;

    }
};