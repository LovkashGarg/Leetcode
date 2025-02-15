class Solution {
public:
bool solve(string &s,int n, int index,int curr, int total,int target){
    if(index>=n){
      if(total + curr == target){
        return true;
      }
      return false;
    }

    // include in this 
    int val=(s[index]-'0');
    bool flag1= solve(s,n,index+1, curr*10 +val ,total,target);
    // start new 
    total=total+ curr;
    bool flag2= solve(s,n,index +1 , val, total, target );
    return flag1 || flag2;

}

    int punishmentNumber(int n) {
        int ans=1;
       for(int i=2;i<=n;i++){
        // check partition 
        int newnum= i*i;
        string s=to_string(newnum);
        if(solve(s,s.size(),0,0,0,i)){
// try all partioning 
        ans+=(i*i);
        } 
     }
     return ans;
    }
};