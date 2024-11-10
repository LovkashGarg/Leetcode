class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int pointer1=0;
        int pointer2=k;
        int n=nums.size();
        if(n==2){
            return true;
        }
        while(pointer2+k<=n){
            bool flag=true;
            for(int i=0;i<k-1;i++){
                if(nums[pointer1+i]>=nums[pointer1+i+1]   ||  nums[pointer2+i]>=nums[pointer2+ i+1]  ){
                    flag=false;
                    break;
                }
            }
            // cout<<flag<<endl;
            if(flag==true){
                return true;
            }
            pointer1++;
            pointer2++;
        }

        return false;
    }
};