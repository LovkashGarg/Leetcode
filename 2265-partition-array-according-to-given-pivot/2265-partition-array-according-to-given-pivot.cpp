class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int>equal;
         vector<int>less;
        vector<int>great;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==pivot)
            equal.push_back(nums[i]);
        }

       
         for(int i=0;i<n;i++){
            if(nums[i]<pivot){
             less.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
great.push_back(nums[i]);
            }
            
        }
        vector<int>ans;
        ans.insert(ans.end() , less.begin(), less.end());
        ans.insert(ans.end() , equal.begin(), equal.end());
        ans.insert(ans.end() , great.begin(), great.end());

return ans;
    }
};