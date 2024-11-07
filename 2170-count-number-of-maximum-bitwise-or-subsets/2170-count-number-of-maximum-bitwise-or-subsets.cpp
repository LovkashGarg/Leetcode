class Solution {
public:
int count=0;
    void solve(vector<int>&nums,int index,int n,int maximumor,int curror){
        
       
       if(index==n){
        if(curror==maximumor){
        // cout<<index<<endl;
        count++;
       }
        return ;
       }

       // include exclude 

       solve(nums,index+1,n,maximumor,curror | nums[index]);
       solve(nums,index+1,n,maximumor,curror);

    }
    int countMaxOrSubsets(vector<int>& nums) {

       int maximumor=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        maximumor=maximumor | nums[i];
       } 
    //    return maximumor;
       // take all subsets
       int curror=0;
       solve(nums,0,n,maximumor,curror);
       return count;
    }
};