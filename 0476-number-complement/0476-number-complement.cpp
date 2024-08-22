class Solution {
public:
    int findComplement(int num) {
        int n=num;
        string d;
        while(n!=0){
            if(n%2==0){
                // means this bit is 0 
                // i have to add the last bit for this number as 1
                d.insert(0,"1");
            }
            else{
                // means the last bit is 1
                   // i have to add the last bit for this number as 0
                  d.insert(0,"0");
            }
            n=n>>1;
        }
            // cout<<d<<endl;
            long int number=0;
            long pow=1;
            for(int i=d.length()-1;i>=0;i--){
               number =number + int(d[i]-'0')*pow;
               pow=pow*2;
            }
            cout<<INT_MAX<<endl;
        return number;
    }
};