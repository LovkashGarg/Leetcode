class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> s;
        int n = num.size();

        for (int i = 0; i < n; i++) {

            // we removed the element
            while (!s.empty() && k > 0 && s.top() > num[i]) {
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        // remove elements from last if k is greater then zero
        while (k > 0) {
            k--;
            s.pop();
        }

        if (s.empty()) {
            return "0";
        }

        string res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        // remove leading zeroes
        while (res.size() != 0 && res.back() == '0') {
            res.pop_back();
        }

// ex we have all 00000 then res becomes empty 
        if(res.empty()){
            return "0";
        }

        reverse(res.begin(), res.end());

        return res;
    }
};