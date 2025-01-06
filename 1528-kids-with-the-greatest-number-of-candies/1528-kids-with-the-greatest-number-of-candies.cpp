class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

     int maxi=0;
     int n=candies.size();
     for(int i=0;i<n;i++){
maxi=max(maxi,candies[i]);
     }   
  vector<bool>ans(n,false);
     for(int i=0;i<n;i++){
        if(extraCandies + candies[i]>= maxi){
            ans[i]=true;
        }
     }
     return ans;
    }
};