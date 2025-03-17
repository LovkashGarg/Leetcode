class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int n= nums.size();
        map<int,int> m;
        for(int i=0;i< n;i++){
            m[nums[i]]++;
        }

        for(auto i:m){
            if(i.second %2!=0){
                return false;
            }
        }
        
        return true;
    }
};