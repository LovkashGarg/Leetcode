class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        // I have to 
        int l=0;
        int r=0;
        int maxi=nums[0];
        int mini=nums[0];
int n=nums.size();
int maxlen=0;
        while(r<n){
            maxi=max(maxi,nums[r]);
            // if maxi -
            if(maxi-mini >1){
                //means I need to go to larger element 
                l++;
                mini=nums[l];
            }
            else if(maxi-mini <1){
                // means it is zero 
                // therefore 
                r++;

            }
            else{
                maxlen=max(maxlen,r-l+1);
                r++;
            }
        }
        return maxlen;
        
    }
};