class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0;
        int r=0;
       long long int sum=0;
        int n=nums.size();
long long int score=0;
long long int count =0;
        while(r<n){
            sum +=nums[r];
            int len=(r-l+1);
             score=sum*len;
             if(score<k){
           count+=(len);
           r++;
             }
             else{

// shrink 
              while(l<r && score >=k){
                sum-=nums[l];
                len--;
                score=sum*len;
                l++;
              }

              // if still in single element not satisfied 
              if(score>=k){
                r++;
              }
              else{
                // compensate the current element since we have added it 
                sum-=nums[r];
              }

             }
        }
        return count;
    }
};

