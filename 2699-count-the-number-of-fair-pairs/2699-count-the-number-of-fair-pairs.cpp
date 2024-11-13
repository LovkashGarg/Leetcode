class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
     
        sort(nums.begin(),nums.end());
        deque<int>q;
        for(auto i:nums){
          q.push_back(i);
        }

        int n=nums.size();

        long long int ans=0;


        for(int i=0;i<n;i++){
            q.pop_front();
            int low=lower-nums[i];
            int high=upper-nums[i];
            auto left=lower_bound(q.begin(),q.end(),low); // tells how many element 
            auto right=upper_bound(q.begin(),q.end(),high);
            ans+=(right-left);

        }

       return ans;
    }
};