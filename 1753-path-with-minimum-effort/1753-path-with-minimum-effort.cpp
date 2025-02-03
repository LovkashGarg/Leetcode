class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        //  if(m==1 && n==1){
        //     return 0;
        //  }
        vector<vector<int>> maxabs(m,vector<int>(n,1e6));
       
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>> > , greater<pair<int,pair<int,int>> > > pq;
        pq.push({0,{0,0}});
vector<int>dirrow={-1,0,1,0};
vector<int>dircol={0,1,0,-1};
maxabs[0][0]=0;
// vector<vector<int>> visited(m,vector<int>(n,0));

        while(!pq.empty()){
            auto temp=pq.top();
            int diff= temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            // visited[x][y]=1;
            pq.pop();

            for(int k=0;k<4;k++){
               int newrow=x+ dirrow[k];
               int newcol=y+ dircol[k];

             if(newrow >=0 && newrow<m && newcol >=0 && newcol < n ){
               int newdiff=abs(heights[x][y]-heights[newrow][newcol]);
               newdiff=max(diff,newdiff);
               if(newdiff < maxabs[newrow][newcol]){
                maxabs[newrow][newcol]= newdiff;
                pq.push({newdiff,{newrow,newcol}});
               }
             }
               
            }

            
        }

        return maxabs[m-1][n-1];
    }
};