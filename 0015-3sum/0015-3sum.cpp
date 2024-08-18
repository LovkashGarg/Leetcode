class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<vector<int>,int>m;
        int n=nums.size();
        vector<vector<int>>ans;
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
    
                 if(m.find(temp)==m.end()){
                 ans.push_back(temp);
                 m[temp]=1;
                 }
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
        return ans;
    }
};