class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>m;
        int n=s.size();
        for(int i=0;i<n;i++){
            string d;

            for(int j=i;j<n;j++){
            d+=s[j];
            m[d]++;
            }
        }

        int l=-1;
        for(auto i: m){
          
            int x=i.first.size();
          if(i.second>=3){
            // also check if it is special or not 
            bool flag=true;
            string c=i.first;
            char o=c[0];
            for(int k=1;k<x;k++){
                if(o!=c[k]){
                flag=false;
                break;
                }
            }
            if(flag==true){
            l=max(l,x);
            }
          }
        }
        return l;


    }
};