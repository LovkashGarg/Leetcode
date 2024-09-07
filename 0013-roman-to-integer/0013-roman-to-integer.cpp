class Solution {
public:
    int romanToInt(string s) {
        int number=0;
        int i=0;
        int n=s.length();
         while(i<n){
             int value=0;
            if(s[i]=='I' ){
                value +=1;
             if(i+1 <n && s[i+1 ]=='V'){
                value+=3;
                i++;
             }
             else if(i+1 <n && s[i+1 ]=='X'){
                value+=8;
                i++;
             }
            }
            else if(s[i]=='V'){
                value+=5;
            }
            else if(s[i]=='X'){
                 value+=10;
                if(i+1 <n && s[i+1 ]=='L'){
                 value+=30;
                 i++;
                }
                else if(i+1 <n && s[i+1]=='C'){
                    value+=80;
                    i++;
                }
            }
            else if(s[i]=='L'){
                value+=50;
            }
            else if(s[i]=='C'){
                value+=100;
                if(i+1<n && s[i+1]=='D'){
                    value+=300;
                    i++;
                }
                else if(i+1 <n && s[i+1]=='M'){
                    value+=800;
                    i++;
                }
            }
             else if(s[i]=='D'){
                value+=500;
            }
            else{
                value+=1000;
            }
            number+=value;
            i++;
         }
         return number;
    }
};