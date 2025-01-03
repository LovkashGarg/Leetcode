class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int,int>m;
        int n=arr.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            maxi=max(maxi,m[arr[i]]);
        }
      vector<int>visited(maxi+1,0);
       for(auto i:m){
        if(visited[i.second]==1){
            // not unique
            return false;
        }
        else{
           visited[i.second]=1;
        }
       }
       return true;
    }
};