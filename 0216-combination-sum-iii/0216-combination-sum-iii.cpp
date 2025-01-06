class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k, int n, int sum,int index,vector<int>output){
        if(index==10){
            if(sum == n && k==0){
                ans.push_back(output);   
            }
            return ;
        }

         // include exclude 
         
         if(k>=1){
            output.push_back(index);
           solve(k-1,n, sum+index,index+1,output);
             output.pop_back();
         }
          
         solve(k,n,sum,index+1,output);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>output;
        int sum=0;
         solve(k,n,sum, 1,output);
         // time complexcity is O(9ck)
         return ans;
    }
};