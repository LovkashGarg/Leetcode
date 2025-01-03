class Solution {
public:
    string removeStars(string s) {

        int n = s.size();
        vector<int> visited(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {

            if (s[i] == '*') {
                while (!st.empty() && s[st.top()] == '*') {
                    st.pop();
                }
                if (!st.empty()) {
                    visited[st.top()] = 1;
                    st.pop(); //remove that character 
                    visited[i]=1;
                }
            }

            st.push(i);
        }
        
string ans;
        for(int i=0;i<n;i++){
         if(visited[i]==0){
            ans+=s[i];
         }
        }
        return ans;
    }
};