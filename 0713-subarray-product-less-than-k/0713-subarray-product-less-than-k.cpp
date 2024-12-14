class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // not possible 
        if(k<=1){
return 0;
        }
        long int product=1;
        int l=0;
        int r=0;
        int n=nums.size();
        int count=0;

        // one case
        // int total=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<k){
        //         total++;
        //     }
        // }
        // if(total <=1){
        //     return total;
        // }

        while(r<n){
            product=product*nums[r];
            if(product <k){
            // Here we donot duplicate one 
            // we count from backward
            count +=(r-l+1);
            r++;
            }
            else {
                    // equal hoga to do barr divide ho jayega 
                    
               while(l<r && product >=k){
                product=product/nums[l];
                l++;
               }

               // agar abhi bhi jayada araha hai single element me bhi to r ko ki bda de 
               // or agar kam me kam chalsakta hai to rehne de 
               if(product >=k){
                r++;
               }else{
               product= product /nums[r];
               }
               
        
            }

        }
        return count;

    }
};