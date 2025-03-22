class Solution {
public:
   void solve(int i,int j, string &s,string &ans,string temp, int n){
    
    while(i>=0 && j<n){
      if(s[i]==s[j]){
          temp= s[i]+ temp;
          temp= temp+ s[j];
          i--;
          j++;
      }
      else{
        break;
      }
    }

     if(temp.size() >ans.size()){
      ans=temp;
     }

   }
    string longestPalindrome(string s) {
        
         string ans;
         ans+=s[0];

         int n=s.size();

            string temp;
        for(int i=1;i<n;i++){

            solve(i-1,i,s,ans,temp,n);
            temp+=s[i];
            solve(i-1,i+1,s,ans,temp,n);
            temp.clear();

        }

        return ans;
    }
};