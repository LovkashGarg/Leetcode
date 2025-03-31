class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<int>inc(n,1);
        vector<int>count(n,1);

        if(n<=1){
            return 1;
        }

        int maxlen=1;
         for(int curr=1;curr<n;curr++){
            
            for(int prev=curr-1;prev>=0;prev--){

                if(nums[prev] < nums[curr] ){
                     if(inc[prev]+1 > inc[curr]){

                         inc[curr]= inc[prev]+1;
                         count[curr]= count[prev];

                     }
                     else if ( inc[prev]+1 == inc[curr]){
                      count[curr]+= count[prev];
                     }
                    
                }

                maxlen=max(maxlen, inc[curr]);

            }
            
        }
        
        int no=0;
        for(int i=0;i<n;i++){
            if(inc[i]== maxlen){
                no+=count[i];
            }
        }

        return no;

    }
};