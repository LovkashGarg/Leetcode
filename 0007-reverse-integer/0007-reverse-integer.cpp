class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        if(s.length()<=1){
          return x;
        }
        bool flag=true;
        // cout<<s<<endl;
        
        if(s[0]=='-'){
         flag=false;
        //  cout<<"negative"<<endl;
         s.erase(0,1);
        }
         int n=s.length();
        for(int i=0;i<n/2;i++){
            swap(s[i],s[n-i-1]);
        }
        if(s[0]=='0'){
            s.erase(0,1);
        }
        long long int  number=0;
        for(int i=0;i<s.length();i++){
            number=number*10+ int(s[i]-'0');
            if(number>(INT_MAX)){
                cout<<number<<endl;
                return 0;
            }
        }
        if(flag==false){
            long long int d=-1;
            number=number*d;
        }
        return number;
    }
};