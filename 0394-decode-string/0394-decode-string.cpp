class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ']') {
                st.push("]");
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                string temp;
                temp += s[i];
                st.push(temp);
            } else if (s[i] == '[') {
                string temp;
                // Build temp from stack until you hit the closing bracket
                while (!st.empty() && st.top() != "]") {
                    temp += st.top();
                    st.pop();
                }
                st.pop(); // Remove the "]"
                
                int number = 0;
                i--;  // Move left to read the number
                
                int placevalue = 1;
                while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
                    int d = int(s[i] - '0');
                    number = number + d * placevalue;
                    placevalue *= 10;
                    i--;
                }
                i++; // Adjust index back after number parsing
                
                // Correctly repeat 'temp' number times
                string newstring = "";
                for (int k = 0; k < number; k++) {
                    newstring += temp;
                }
                st.push(newstring);
            }
        }
        while(!st.empty()){
            ans= ans +  st.top() ;
            st.pop();

        }
        
        return ans;
    }
};
