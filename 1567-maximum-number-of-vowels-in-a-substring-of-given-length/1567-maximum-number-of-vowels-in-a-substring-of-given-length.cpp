class Solution {
public:
    int maxVowels(string s, int k) {
        int totalmax = 0;
        int maxstart = 0;
        int n = s.length();
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||   s[i] == 'u') {
              count++;
           }
         }
         totalmax = max(totalmax, count);
         count=totalmax;
    for (int i = k; i < n; i++) {
        if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' ||
            s[i-k] == 'u'){
                   count--;
                   
        }
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u') {
               count++;
        }
        totalmax=max(totalmax,count);
    }
    cout << totalmax<<endl;
    return totalmax;
}
}
;