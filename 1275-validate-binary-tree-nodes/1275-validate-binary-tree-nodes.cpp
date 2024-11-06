class Solution {
public:
    bool ans=true;
    void dfs(int node,int n,vector<int>& leftChild, vector<int>& rightChild,vector<int>&visited ){
        if(node==-1){
            return ;
        }
        // cout<<node<<endl;
         if(visited[node]==1){
            ans=false;
            return;
        }
        visited[node]=1;
       

        dfs(leftChild[node],n,leftChild,rightChild,visited);
        dfs(rightChild[node],n,leftChild,rightChild,visited);

    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // do a dfs if allready visited then return false
         vector<int> visited(n,0);
         // firstly find root 
        
        // here all of the nodes have indegree 1 but root node have indegree 0
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){

           indegree[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
             indegree[rightChild[i]]++;
            }
        }

        int root=n+1;
        for(int i=0;i<n;i++){
            // cout<<indegree[i]<<endl;
            if(indegree[i]==0){
              root=i;
              break;
            }
        }

        // no root present
        if(root==n+1){
            return false;
        }

        dfs(root,n,leftChild,rightChild,visited);

        // one case of disconnected components 
        if(ans==true){
         for(int i=0;i<n;i++){
            if(visited[i]==0){
                return false;
            }
          }
        }
       
        return ans;
    }
};