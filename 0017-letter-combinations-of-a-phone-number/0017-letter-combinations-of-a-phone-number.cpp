class Solution {
public:
   void solve(string digits, map<char, string>m, vector<string> &ans,string s, int index, int n ){
    if(index==n){
        ans.push_back(s);
        return ;
    }
    string d=m[digits[index]];
    for(int i=0;i< d.length();i++){
        solve(digits, m, ans, s+ d[i],index+1, n);
    }

   }
    vector<string> letterCombinations(string digits) {
      map<char,string>m;
      m['2']="abc";
      m['3']="def" ;
      m['4']="ghi";
      m['5']="jkl";
      m['6']="mno";
      m['7']="pqrs";
      m['8']="tuv";
      m['9']="wxyz";

      vector<string> ans;
      string s="";
      int n=digits.length();
      if(n==0){
        return ans;
      }
      solve(digits, m, ans, s, 0,n);
    return ans;
      }
    };