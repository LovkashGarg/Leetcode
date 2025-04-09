class Solution {
public:



    int count(int n ,char lastchar ,unordered_map<int,int>&m,vector<vector<int>>&dp){
        // no char left means string complete 
        if(n==0){
            return 1;
        }
        if(dp[m[lastchar]][n]!=-1){
            return dp[m[lastchar]][n];
        }
        int total=0;
        
         if(lastchar =='a'){
       total += count(n-1,'a',m , dp);
       total += count(n-1,'e',m , dp);
       total += count(n-1,'i',m , dp);
       total += count(n-1,'o',m , dp);
       total += count(n-1,'u',m , dp);
         }
         else if(lastchar=='e'){
       total += count(n-1,'e',m , dp);
       total += count(n-1,'i',m , dp);
       total += count(n-1,'o',m , dp);
       total += count(n-1,'u',m , dp);
         }
         else if(lastchar =='i'){
             total += count(n-1,'i',m , dp);
       total += count(n-1,'o',m , dp);
       total += count(n-1,'u',m , dp); 
         }
         else if(lastchar=='o'){
            total += count(n-1,'o',m , dp);
       total += count(n-1,'u',m , dp); 
         }
         else{
            total += count(n-1,'u',m , dp); 
         }
         return dp[m[lastchar]][n]=total;

    }
    int countVowelStrings(int n) {
     
     unordered_map<int,int>m;
m['a']=0;
m['e']=1;
m['i']=2;
m['o']=3;
m['u']=4;
vector<vector<int>>dp(5,vector<int>(n+1,-1));
       int total = count(n-1,'a',m , dp);
       total += count(n-1,'e',m , dp);
       total += count(n-1,'i',m , dp);
       total += count(n-1,'o',m , dp);
       total += count(n-1,'u',m , dp);
      return total;

    }
};