class Solution {
public:
    vector<int> grayCode(int n) {
       vector<int> ans;
       ans.push_back(0);
       if(n==0){
        return ans;
       }
       ans.push_back(1);
       int curr=1;

// doing for n -1 times 
       for(int i=2;i<=n;i++){
   curr=curr*2;
   for(int j=ans.size()-1;j>=0;j--){
    ans.push_back(curr + ans[j]);
   }
       }
        
       return ans;
    }
};