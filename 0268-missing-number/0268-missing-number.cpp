class Solution {
public:

    int missingNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]=1;
        }

        for(int i=0;i<n;i++){
            if(!m.count(i)){
return i;
            }
        }
        
        return n;
    }
};