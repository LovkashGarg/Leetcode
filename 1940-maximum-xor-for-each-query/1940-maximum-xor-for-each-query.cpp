class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        

        // firstly find the xor of all the ele
        int n=nums.size();
        int xorval=0;
        for(int i=0;i<n;i++){
            xorval=xorval^ nums[i];
        }
vector<int>ans;
        // now for n queries 
        for(int i=n-1;i>=0;i--){
            // first query last ele is present 

            // now check max number possible 
            int k=0; // I would set if the xor of array is unset and vice versa 
            for(int j=0;j<maximumBit;j++){

                // if that bit is set
               if(( xorval &(1<<j) ) !=0){
             
                // do nothing 
                k=k;
               }
               else{
                   k=((1<<j)|k);
               }
              
            }
            // cout<<k<<endl;
            ans.push_back(k);
            // to cancel out the effect of last element
            xorval=xorval^nums[i];

        }
        return ans;
    }
};