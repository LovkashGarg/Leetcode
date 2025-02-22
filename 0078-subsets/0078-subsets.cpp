class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // here a
        int subsets= 1<< nums.size();
        vector<vector<int>>subs(subsets);

        for(int i=0;i<subsets;i++){


           for(int j=0;j<nums.size();j++){
                if(((i>>j) &1)==1){
                    subs[i].push_back(nums[j]);
                }
           }

        }
        
        return subs;






    }
};