#include<bits/stdc++.h>
class Solution {
public:
    int maximumSum(vector<int>& nums) {

       map<int,multiset<int> > mp;
       int n= nums.size();
       for(int i=0;i<n;i++){
            
            int val= nums[i];
            int sum=0;
            while(val){
                int d= val %10;
                sum+=d;
                val=val/10;
            }

            mp[sum].insert( nums[i] );
       }
       
       int maxi=-1;
       for(auto i: mp){
        int c=i.second.size();
           if(c>=2 ){
          int lastsecond= *next(i.second.rbegin());
          int last= *(i.second.rbegin());
            maxi=max(maxi, lastsecond + last);
           }
       }

       return maxi;
    }
};