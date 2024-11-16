class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
      // total subarray possible 
 
      int n=nums.size();
      vector<int>v;
      // cover all the subarray 

        for(int i=0;i+k-1<n;i++){

            // start with first element 
           
            int ans=nums[i];
            int d=0;
            bool flag=true;

            for(int j=i;d<k-1;j++){

              if(nums[j]!= (nums[j+1] -1) ){
                flag=false;
                   break;
              }

              ans=max(ans,max(nums[j],nums[j+1]));
            //   cout<<i<<" "<<ans<<endl;
              d++;
            }
               if(flag==false){
                v.push_back(-1);
               }
               else{
               v.push_back(ans);
               }

        }


        return v;
    }
};