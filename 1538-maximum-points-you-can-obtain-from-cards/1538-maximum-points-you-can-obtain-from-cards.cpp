class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
      
        int totalsum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(k==n){
            return totalsum;
        }
        int d=0; // now we are trying to remove a sub array with n-k that have min sum 
        int l=0;
        int r=(n-k-1);
        int sumcurr=0;
        for(int i=0;i<r;i++){
        sumcurr+=cardPoints[i];
        }
        // cout<<sumcurr<<endl;
       long long int answer=0;
        while(r<n){
            sumcurr=sumcurr+ cardPoints[r];
            r++;
            if(answer< (totalsum- sumcurr)){
                answer=totalsum-sumcurr;
            }
            sumcurr=sumcurr-cardPoints[l];
            l++;
        }

        return answer;
          
    }
};