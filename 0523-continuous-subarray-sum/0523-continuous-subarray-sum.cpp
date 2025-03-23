class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        long long prefixsum=0;
        map<long long ,int>m;
        int n=nums.size();
        int maxlen=0;
        m[0]=-1;
        for(int i=0;i<n;i++){

           prefixsum+=nums[i];
            prefixsum%=k;

        //    if(prefixsum==0){
        //      maxlen=i+1;
        //    }

// matlab bich vale sare milke equal to 0 hogye 
           if(m.find(prefixsum) !=m.end()){
              maxlen=max(maxlen,i-m[prefixsum]);  
           }

           else{
           m[prefixsum]=i;
           }

        }

          if(maxlen>=2){
            return true;
           }

        return false;
    }
};