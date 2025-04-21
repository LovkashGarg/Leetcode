class Solution {
public:

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        long long int x=0;
        long long int mini=0;
        long long int maxi=0;

        //  I find teh all the elements 
        int n = differences.size();

        for(int i=0;i<n;i++){
            long long  val= x + differences[i];
            x=val;
            mini=min(mini, val);
            maxi=max(maxi,val);
        }

        // no of possible values =
        int ans= (upper -lower +1) - (maxi-mini);
        if(ans <0){
            return 0;
        }
        return ans;


    }
};