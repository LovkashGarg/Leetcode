class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
int n=nums.size();
          int  closestsum =INT_MAX;
         int ans=0;
        for(int i=0;i<n-2;i++){
            cout<<i<<endl;
           int j=i+1;
           int k=n-1;
           int sum=nums[i];
           while(j<k){
            int newsum=sum+ nums[j]+ nums[k];
            if(target ==newsum){
               return target;
            }
            else if(target >newsum){
                if(closestsum> target-newsum){
                closestsum=min(closestsum,target-newsum);
                  ans= newsum;
                }
                // cout<<"closestsum"<<closestsum<<endl;
                j++;
            }
            else{
                if(closestsum> newsum-target){
                closestsum=min(closestsum,newsum-target);
                  ans= newsum;
                 }
                // cout<<"closestsum"<<closestsum<<endl;
                 k--;
              }
           }
        }
        return ans;
    }
};