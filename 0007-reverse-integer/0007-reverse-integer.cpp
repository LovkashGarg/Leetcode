class Solution {
public:
    int reverse(int x) {
        bool flag=true;
        if(x<0 ){
            if(x==INT_MIN){
                return 0;
            }
            flag=false;
            x=x*-1;
        }
        long long int number=0;
        cout<<INT_MAX<<endl;
        while(x!=0){
            int d=x%10;
            cout<<number<<endl;
            number=number*(10) + d;
            if(number>INT_MAX){

                // cout<<"Hello "<<endl;
                return 0;
            }
            x=x/10;
        }
        if(flag==false){
            number=number*(-1);
        }
        return number;
    }
};