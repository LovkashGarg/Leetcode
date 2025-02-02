class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return true;
        }
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }

        // now I would check if a n length sorted present or not 

        int maxlen=0;
        int i=0;
        while(i<2*n){

           int len=1;
           while(((i+1)<2*n) && nums[i]<=nums[i+1]){
              len++;
              i++;
           }
           i++;
          maxlen=max(maxlen,len);

        }
        
        if(maxlen>=n){
            return true;
        }
        return false;
    }
};