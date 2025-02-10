class Solution {
public:
    string clearDigits(string s) {
        
        stack<char>st;
        int n=s.size();
        
        for(int i=0;i<n;i++){
         if(s[i]>='0' && s[i]<='9'){
               auto c= st.top();
               st.pop();
         }
         else{
            st.push(s[i]);
         }

        }
        string ans;
        while(!st.empty()){
            ans= st.top()+ ans;
            st.pop();
        }
        return ans;
    }
};