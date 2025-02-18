/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        // first push in string 
        string s;
        if(root==nullptr){
            return s;
        }
        queue<TreeNode *>q;
        q.push(root);
        s+=(to_string(root->val));
        s+=',';
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    s+=(to_string(temp->left->val));
                    s+=',';
                }
                else{
                  s+="#,";
                 
                }
                if(temp->right){
                    q.push(temp->right);
                    s+=(to_string(temp->right->val));
                    s+=',';
                }
                else{
                   s+="#,";
                }
            }

        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        if(data.size()==0){
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode *>q;
        TreeNode *root=new TreeNode (stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                node->left=nullptr;
            }
            else{
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }

           getline(s,str,',');
            if(str=="#"){
                node->right=nullptr;
            }
            else{
                node->right=new TreeNode(stoi(str));
                 q.push(node->right);
            }
            
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));