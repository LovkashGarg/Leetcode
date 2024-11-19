class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>m;
        int n=arr.size();
        int j=1;
        for(int i=0;i<n;i++){
            if(m.find(temp[i])==m.end()){
            m[temp[i]]=j++;
            }
        }
         
        for(int i=0;i<n;i++){
          arr[i]=m[arr[i]];
        }
        return arr;
    }
};