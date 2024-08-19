class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       set<vector<int>>s;
        int n=nums.size();
      
        for(int i=0;i<n-2;i++){
            // element will be inside this 
            int j=i+1; 
            int k=n-1;
            int target=-nums[i];
            while(j<k){
            int sum= nums[j]+ nums[k];
             if(target==sum){
                // cout<<"hello"<<j<<" "<<k<<endl;
                vector<int> temp={nums[i],nums[j],nums[k]};
                    s.insert(temp);
                j++;
                k--;
             }
              else if(target >sum){
                j++;
            }
              else {
                k--;
             }
            }
        }
          vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};