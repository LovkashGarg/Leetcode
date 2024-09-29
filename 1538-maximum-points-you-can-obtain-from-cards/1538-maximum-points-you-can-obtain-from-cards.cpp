class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     int lsum=0,rsum=0,maxsum=0;
     // taken all the elements 
     for(int i=0;i< k;i++){
         lsum+= cardPoints[i];
     }
     int n=cardPoints.size();
     int rindex=n-1;
     maxsum =lsum;
// means i am trying to remove element of left and add one element in right 
     for(int j=k-1;j>=0;j--){
      lsum =lsum -cardPoints[j];

      rsum =rsum + cardPoints[rindex];
      rindex--;
      maxsum=max(maxsum ,lsum + rsum);
     }
     return maxsum;
    }
};