class Solution {
public:
    bool isIsomorphic(string s, string t) {
int n=s.size();
     unordered_map<char,char>m;
     vector<int>v(256,-1);
     for(int i=0;i<n;i++){
        if(m.find(s[i])!=m.end() && m[s[i]] !=t[i]){
         return false;
        }
        // agar key nhi hai map me to then 
        if(m.find(s[i])==m.end()){
            // already mapped hai to some other character  to return false 
            if(v[t[i]]==1){
                return false;
            }
            v[t[i]]=1;
            m[s[i]]=t[i];
        }
     }
     return true; 
    }
};