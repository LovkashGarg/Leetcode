class Solution {
public:
    int addDigits(int num) {
        if(num<=9){
            return num;
        }
        string s=to_string(num);
        int n=s.size();
        int number=0;
        for(int i=0;i<n;i++){
number+=(s[i]-'0');
        }
        
        return addDigits(number);
    }
};