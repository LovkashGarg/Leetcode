class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
      
      
        int n=nums.size();
        multiset<int>s;

       
        
        for(int i=0;i<n;i++){
            
            // I have to do binary search for both elements
            auto it1 = s.lower_bound(nums[i]-valueDiff); // Finds the first element >= nums-valueDiff
            // ex here is for 3 find 3-0 means find 3 here we donot have element greater then 3 hence 
            // also now for 1 we find element 1-0 means 1 is present also now 1- 1 =0 means there diff is less than valueDiff hence it is true 
              if (it1 != s.end() && abs(nums[i]-*it1) <=valueDiff) {
      return true;
            }

        
            s.insert(nums[i]);
            if(s.size() >indexDiff){
            s.erase(nums[i-indexDiff]);
            }

        }
        return false;
         

        
        return false;
    }
};