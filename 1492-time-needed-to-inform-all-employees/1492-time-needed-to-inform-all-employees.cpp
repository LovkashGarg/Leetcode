class Solution {
public:
// time min is 0;
int maxi=0;
void bfs(int headId, vector<vector<int>>&tree,vector<int>&informTime){
    queue<pair<int ,int>> q;
    q.push({headId,0});
    // level order traversal 
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            int temp=q.front().first;
            int time=q.front().second;
            time = time + informTime[temp];
            maxi=max(maxi,time);
            q.pop();
            for(auto employee:tree[temp] ){
              q.push({employee,time});
            }
        }
    }
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       // no of employees =6 
       // make a tree first 
       vector<vector<int>>tree(n);
       for(int i=0;i<n;i++){
        // niche kon kon hai 
         if(i !=headID){
         tree[manager[i]].push_back(i);
         }
       }
       // do a dfs travesal 
      bfs(headID,tree,informTime);
      return maxi;
    }
};