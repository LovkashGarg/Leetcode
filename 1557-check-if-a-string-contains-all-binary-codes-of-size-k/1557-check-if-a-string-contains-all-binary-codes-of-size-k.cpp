class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>m;
        
int n=s.size();
if(n <k){
            return false;
        }
        string temp;
        for(int i=0;i<k-1;i++){
            temp+=s[i];
        }

        for(int i=k-1;i<n;i++){
            
            temp+=s[i];
            m.insert(temp);

            temp.erase(0,1); // log n 
        }

        if(m.size()== pow(2,k)){
            return true;
        }
        return false;

    }
};