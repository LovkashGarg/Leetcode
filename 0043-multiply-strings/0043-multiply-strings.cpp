
class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        if(num1[0]=='0' || num2[0]=='0'){
            return "0";
        }
        int n1 = num1.size();
        int n2 = num2.size();
        vector<string> ans(n2, "");
        int k = 0;
        for (int i = n2 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n1 - 1; j >= 0; j--) {
                int numb = (num2[i] - '0') * (num1[j] - '0') + carry;
                int d = numb % 10;
                carry = (numb / 10);
                ans[k] = string(1, d + '0') + ans[k];
            }

            if (carry > 0) {
                ans[k] = string(1, '0' + carry) + ans[k];
            }

            if (k != 0) {
                string zeroes(k, '0');
                ans[k] = ans[k] + zeroes;
            }
            k++;
        }
        
        if (n2 ==1){
            return ans[0];
        }
            int j = ans[ans.size()-1].size();
        // total n1 rows of strings
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = string(j - ans[i].size(), '0') + ans[i];
        }
        for (auto d : ans) {
            cout << d << endl;
        }
        int carry = 0;
        // for every string character
        int l = j - 1;
        string finalans;
        for (int i = 0; i < j; i++) {
            long long sum = 0;
            for (int d = 0; d < ans.size(); d++) {
                sum += (ans[d][l] - '0');
            }
            sum += carry;
            carry = sum / 10;
            finalans = string(1, sum % 10 + '0') + finalans;
            l--;
        }
         if (carry > 0) {
                finalans = string(1, '0' + carry) + finalans;
         }
        return finalans;
    }
};