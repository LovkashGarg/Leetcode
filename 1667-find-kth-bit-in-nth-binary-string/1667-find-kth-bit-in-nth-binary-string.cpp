class Solution {
public:
   map<int,string>dp={{1,"0"},{2,"011"},{3,"0111001"}};
    string reverse_invert(string a){
       
       // first invert
       for(int i=0;i<a.size();i++){

        if(a[i]=='1'){
            a[i]='0';
        }
        else{
            a[i]='1';
        }
       }

       reverse(a.begin(),a.end());
       return a;
    }

   string solve(int n){
    
    if(dp.count(n)){
        return dp[n];
    }
    
    // generate for each and every one 
    return dp[n]=  solve(n-1) + '1' + reverse_invert(solve(n-1));

   }
    char findKthBit(int n, int k) {
        
        string s=solve(n);
        return s[k-1];
    }
};