class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {



     //make a adjacency list
     int n=quiet.size();
     vector<vector<int>>adj(n);  
     for(int i=0;i<richer.size();i++){
        // means all the element in the adjacency list are having less money then the parent element 
        adj[richer[i][0]].push_back(richer[i][1]);
     } 
    vector<int>indegree(n,0);

    for(int i=0;i<n;i++){
        for(auto adj_node:adj[i]){
            indegree[adj_node]++;
        }
    }
    
    vector<int>ans(n,INT_MAX);
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        ans[i]=i;
        if(indegree[i]==0){
            q.push({i,0});
        }
    }
    while(!q.empty()){
        int node=q.front().first;
        int level=q.front().second;

        q.pop();
        for(auto adj_node:adj[node]){

            if(quiet[ans[adj_node]] > quiet[ans[node]]){
                 ans[adj_node] = ans[node];
            }

            indegree[adj_node]--;
            if(indegree[adj_node]==0){
                q.push({adj_node,level+1});
            }
            
        }
    }

    return ans;
    
    }
};