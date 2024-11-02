class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i=0;
        int n=sentence.length();
        char lastchar;
        while(i<n){
            while(i+1<n && sentence[i+1]!=' '){
                i++;
            }
            // last character is 
            lastchar=sentence[i];
            char firstchar='0';
            if(i+1 <n ){
                // first char of next word is 
            firstchar=sentence[i+2];
            }
            if(i+1 <n && lastchar!=firstchar){
            return false;
            }
            i++;
        }
 if(sentence[0]== sentence[n-1]){
return true;
 }
 return false;
    }
};