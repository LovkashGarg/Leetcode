class Solution {
public:
    long long int requiredtime(vector<int> & piles,int k,int h){
        int n=piles.size();
        long long int totaltime=0;
        for(int i=0;i<n;i++){
             totaltime+=(ceil(double(piles[i])/double(k)));
        }
        return totaltime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=INT_MIN;
        if(n==1){
            int ans=piles[0]/h;
            int modul=piles[0]%h;
            if(modul >0){
                return 1+ ans;
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        // here max speed which can lead to smallest hour = max of all 
        // then it would take one hour for  each pile 
        
        // range of koko speed is 1 to maxi
        // here we 
        int low=1;
        int high=maxi;
         int ans=maxi;
        while(low<=high){

        int mid=low +(high-low)/2;
            long long int  reqtime=requiredtime(piles,mid,h);
           
            if(reqtime<=h){
                ans=mid; 
                high=mid-1; // ham ab slow speed ki taraf ja sakte hai
            }
            else {
                low=mid+1; // matlab hame high speed chahiye 
            }
        }
        // time complexicity o(n*max(piles))
        return ans;

    }
};