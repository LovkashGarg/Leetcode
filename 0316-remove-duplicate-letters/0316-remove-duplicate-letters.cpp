class Solution {
public:
    string removeDuplicateLetters(string s) {
         int n= s.size();
         stack<char>st;
         string res;
         vector<int>visited(26,0);
         vector<int>last(26);
         for(int i=0;i<n;i++){
           last[s[i]-'a']=i;
         }

         for(int i=0;i<n;i++){
            char c = s[i];
            if(visited[c-'a']){
                continue;
            }
          // My main target is to find the greater element that are present in my ans which can be replaced with some next character after wards 
            while(!st.empty() && st.top()> c  && last[st.top()-'a'] >i){
                visited[st.top()-'a']=false;
                st.pop();
            }
            

            // would be pushed only when unvisited 
            st.push(c);
            visited[c-'a']=true;

         }

         while(!st.empty()){
            res+=st.top();
            st.pop();
         }

         reverse(res.begin(), res.end());
         return res;

    }
};