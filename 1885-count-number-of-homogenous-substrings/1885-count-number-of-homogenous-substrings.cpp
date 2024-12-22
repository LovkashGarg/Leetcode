class Solution {
public:
    int countHomogenous(string s) {
        vector<int>v(26,-1);
         int mod=1e9 +7;
         long long int total=0;
        int l=0;
        int r=0;
        int n=s.size();
        while(r<n){

             if(v[s[r]-'a'] == v[s[l]-'a']){
                total=(total + (r-l+1)%mod)%mod; // no of subarray on left from it 
             }
             else{

                l=r;

                if(v[s[r]-'a'] == v[s[l]-'a']){
                  total=(total + 1)%mod; 
                }
             }

             v[s[r]-'a']=r;
             r++;
             
        }
        return total;
    }
};