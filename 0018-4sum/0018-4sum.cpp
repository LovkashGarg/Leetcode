class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        // I want to find all the four length subarray 
        set<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                
                 // I need to find the two element 

                 // my target to find the target - sum 
                
                 for(int k=j+1;k<n-1;k++){
long long sum=nums[i]+ 0ll+ nums[j]+ nums[k];
 long long newtarget= target-sum;
                  int left=k+1;
                 int right=n-1;
                 while(left<=right){
                    int mid= (left+ right)/2;
                    if(newtarget == nums[mid]){
                        ans.insert({nums[i],nums[j],nums[k],nums[mid]});
                        int val1= nums[left];
                        int val2=nums[right];
                       while(left< n && nums[left]== val1){
                        left++;
                       }
                       while(right>=0 && nums[right]== val2){
                        right--;
                       }

                    }
                    else if(newtarget > nums[mid]){
                        left=mid+1;
                    }
                    else{
                        right=mid-1;
                    }
                 }

                 }

                



            }
        }

        return vector<vector<int>>(ans.begin(),ans.end());
    }
};