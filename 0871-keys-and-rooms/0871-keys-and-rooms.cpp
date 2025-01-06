class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        // now we have to make a adj matrix no need
        int n=rooms.size();
        vector<int>visited(n,0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node= q.front();
            visited[node]=1;
            q.pop();

            for(auto i: rooms[node]){
               if(!visited[i]){
                q.push(i);
               }
            }
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                return false;
            }
        }
        return true;
    }
};