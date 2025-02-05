class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        int n=s1.size();
        for(int i=0;i<n;i++){
               v1[s1[i]-'a']++;
               v2[s2[i]-'a']++;
        }

        if(v1!=v2){
return false;
        }
        else {
            int count=0;
            for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
            }
            }

            if(count <=2){
                return true;
            }
            return false;
        }
    }
};