class Solution {
public:
int totalsum=0;
//    void dfs(int root,vector<vector<int>&adj){
//     for(auto adj_node:adj[root]){
//         if(parent !=adj_node){
//             dfs(adj_node,root,adj);
//         }
//     }
    

//    }

    int dfs(int root, int parent, vector<vector<int>>& adj, int n,
            vector<int>& values, int k,int &count) {

        // I have to return the sum of each
        int sum = 0;
        for (auto adj_node : adj[root]) {

            if (adj_node != parent) {
                sum += dfs(adj_node, root, adj, n, values, k,count);
                sum %= k;
            }
        }

        sum += values[root];
        sum %= k;
        if (sum == 0) {
            count++;
        }
        return sum;
    }
  
 
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n=nums.size();
        for(int i=0;i<n;i++){
          totalsum+=nums[i];
        }


        // do dfstraversal
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        // now 

        // find divisors of the totalsum i.e 
        vector<int>divisors;

        for(int i=1;i<=totalsum;i++){
            if(totalsum %i==0){
                divisors.push_back(i);
            }
        }
        
       
    int ans=0;
        for(auto i:divisors){
            int count=0;
            dfs(0, -1, adj, n, nums, i,count);
            if(count == (totalsum/i) && count!=1){
                ans=max(ans,count-1); // we have to d
            }

        }
       
        

return ans;

    }
};