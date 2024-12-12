class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        if(m>n){
            return {};
        }

       
        vector<int>v(26,0);
         map<int,int>mp;
         for(int i=0;i<m;i++){
            mp[p[i]-'a']++;
         }

        for(int i=0;i<p.size()-1;i++){
           v[s[i]-'a']++;
        }
       vector<int>ans;

       // time complexicity worst case O( n* 26)
        for(int j=m-1;j<n;j++){
            v[s[j]-'a']++;
             bool flag=true;
            for(auto i:mp){
                if(i.second !=v[i.first]){
                flag=false;
                break;
                }
            }
            if(flag==true){
            ans.push_back((j-m+1));
            }
            v[s[j-m+1]-'a']--;
        }
        return ans;


    }
};