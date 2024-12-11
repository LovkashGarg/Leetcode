class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    map<string,int>m;
    string d;
    int i=0;
     for( ;i<9;i++){
        d+=s[i];
     }
int n=s.size();
     while(i<n){
        d+=s[i];
        m[d]++;
        d=d.substr(1);
        i++;
     }
     vector<string>ans;
     for(auto i: m){
        if(i.second >=2){
        ans.push_back(i.first);
        }
     }
     return ans;
    

    }
};