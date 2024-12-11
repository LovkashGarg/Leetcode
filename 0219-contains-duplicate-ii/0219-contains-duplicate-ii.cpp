class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,int>m;
        int n=nums.size();
        // time complexicity O(n*logn)
        for(int i=0;i<n;i++){
          if(m.find(nums[i])!=m.end()){

             if(i-m[nums[i]]<=k){
                return true;
             }
          }

          m[nums[i]]=i;
        }
        return false;
    }
};