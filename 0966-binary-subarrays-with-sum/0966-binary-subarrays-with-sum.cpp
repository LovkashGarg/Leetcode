class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int l=0;
        int r=0;
        int count=0;
        int sum=0;
        int n=nums.size();
        while(r<n){

            sum+=nums[r];

            if(sum==goal){
                cout<< r<< l<<endl;
                 int d=l;
                 // Here one is due to this subarray I want to check How many l  can shrink that are also counted in subarrays 
                 count++;
                 while(d<r && nums[d]==0){
                    d++;
                    count++;
                 }

                r++;
            }
            else if(sum <goal){
                // or element chahiye
               r++;
            }
            else{

                while(l<r && sum>goal){
                    sum-=nums[l];
                    l++;
                }

                if(sum !=goal){
                    r++;
                }
                else{
                    // count++;
                   sum-=nums[r];
                }
            }
           
        }
          return count;
        
    }
};