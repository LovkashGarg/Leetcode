class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>>s; 
        sort(nums.begin(),nums.end());
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
             
             int low= i+1;
             int high= n-1;
             
             int target= nums[i]+k;
             while(low <=high){
                int mid= (low+high)/2;
                if((target )== nums[mid] ){
                    s.insert({nums[i],nums[mid]});
                    break;
                }
                else if((target)> nums[mid]){
                    low= mid+1;
                }
                else{
                    high=mid-1;
                }
             }

        }

        return s.size();
    }
};