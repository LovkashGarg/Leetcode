class Solution {
public:
bool ans=false;
unordered_set<int>s;
void solve(int n){
    
    // convert to digit  values
    if(s.find(n)!=s.end()){
         return ;
    }

    int sum=0;
    int num=n;
    
    while(num){

        int d=num%10;
        num=num/10;
        sum+=(d*d);
    }
    
    s.insert(n);
    if(sum==1){
        ans=true;
        return;
    }
    else{
        solve(sum);
    }
   

}

    bool isHappy(int n) {
        solve(n);
        return ans;
    }
};