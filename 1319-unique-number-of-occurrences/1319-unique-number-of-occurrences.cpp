class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<vector<int>>a(1001);
        map<int,int>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }

       for(auto i:m){
        cout<<i.first<<i.second<<endl;
        if(a[i.second].size()==1){
            // not unique
            return false;
        }
        else{
            a[i.second].push_back(i.first);
        }
       }
       return true;
    }
};