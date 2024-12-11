class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        multiset<int>m;
        int n=nums.size();
        // time complexicity O(n*logn)
        for(int i=0;i<n;i++){
            // means I have to erase a element one by one 
            if(i>k){
             m.erase(nums[i-k-1]);
            }

            auto it=m.count(nums[i]); // I need to check how many present 
            if(it==1){
                return true;
            }
            m.insert(nums[i]);

        }
       

        return false;
    }
};