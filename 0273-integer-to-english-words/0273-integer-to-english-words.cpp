class Solution {
public:
    string helperFunction(string  t, map<int, string>& m, int type) {
        string ans;
        int number = stoi(t);
        int d;
        t = to_string(number); // Remove leading zeros

        if (t.size() == 3) { // Handle hundreds
            d = t[0] - '0';
            ans += m[d] + " " + m[100] + " ";
            
            int x = (t[1] - '0') * 10 + (t[2] - '0');
            if (x > 0 && x < 20) {
                ans += m[x] + " ";
            } else {
                if (t[1] != '0') ans += m[(t[1] - '0') * 10] + " ";
                if (t[2] != '0') ans += m[t[2] - '0'] + " ";
            }
        } else if (t.size() == 2) { // Handle tens
            int x = stoi(t);
            if (x < 20) {
                ans += m[x] + " ";
            } else {
                if (t[0] != '0') ans += m[(t[0] - '0') * 10] + " ";
                if (t[1] != '0') ans += m[t[1] - '0'] + " ";
            }
        } else { // Handle ones
            d = t[0] - '0';
            if (d != 0 || type == 1) ans += m[d] + " ";
        }

        // Remove trailing space
        if (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        map<int, string> m = {
            {0, "Zero"},          {1, "One"},       {2, "Two"},       {3, "Three"},       {4, "Four"},
            {5, "Five"},          {6, "Six"},       {7, "Seven"},     {8, "Eight"},       {9, "Nine"},
            {10, "Ten"},          {11, "Eleven"},   {12, "Twelve"},   {13, "Thirteen"},   {14, "Fourteen"},
            {15, "Fifteen"},      {16, "Sixteen"},  {17, "Seventeen"},{18, "Eighteen"},   {19, "Nineteen"},
            {20, "Twenty"},       {30, "Thirty"},   {40, "Forty"},    {50, "Fifty"},      {60, "Sixty"},
            {70, "Seventy"},      {80, "Eighty"},   {90, "Ninety"},   {100, "Hundred"},   {1000, "Thousand"},
            {1000000, "Million"}, {1000000000, "Billion"}
        };

        string number = to_string(num);
        string ans;

        if (number.size() >= 10) { // Billions
            string temp = number.substr(0, number.size() - 9);
            ans += helperFunction(temp, m, 4) + " Billion ";
            number = number.substr(temp.size());
        }

        if (number.size() >= 7) { // Millions
            string temp = number.substr(0, number.size() - 6);
            string t=helperFunction(temp, m, 3) ;
            if(t!=""){
            ans += t+ " Million ";
            }
            number = number.substr(temp.size());
        }
       
        if (number.size() >= 4) { // Thousands
            string temp = number.substr(0, number.size() - 3);
            string t=helperFunction(temp, m, 2) ;
            if(t!=""){
            ans += t+ " Thousand ";
            }
            number = number.substr(temp.size());
        }
        
        if (!number.empty()) {
            string t=helperFunction(number, m, 1) ;
            if(t=="Zero" &&  ans.size()==0){
            ans += t;
            }
            else if(t!="Zero"){
            ans += t;
            }
           
        }


        if (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
