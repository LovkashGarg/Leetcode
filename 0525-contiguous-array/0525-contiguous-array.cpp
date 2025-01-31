class Solution {
public:
    int findMaxLength(vector<int>& nums) {

       int n=nums.size();
        for(int i=0;i<n;i++){

            if(nums[i]==0){
            nums[i]=-1; 
            }

        }

        int prefixsum=0;
        map<int,int>m;
       int maxlen=0;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];

            if(prefixsum==0){
              maxlen=i+1; // matlab starting se yha tak 
            }

            if(m.find(prefixsum) !=m.end()){

                maxlen=max(maxlen, i- m[prefixsum] );
            }
            else{ 
             // only update when not found 
            m[prefixsum]=i;
            }
        }

        return maxlen;
    }
};