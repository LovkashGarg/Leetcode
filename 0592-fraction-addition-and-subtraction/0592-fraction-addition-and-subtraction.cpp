class Solution {
public:
    int gcd(int a,int b){
      if(b==0){
        return a;
      }
      return gcd(b,a%b);
    }
    string fractionAddition(string expression) {
        vector<int> num;
        vector<int> deno;
        int n = expression.length();
        for (int i = 0; i < n; i++) {
            // cout<<"i" <<expression[i]<<endl;
            int numer = 1;
            int denom = 1;
            int j;
            if (expression[i] == '-') {
                numer = -1;
                 j = i + 1;
            } else if(expression[i]=='+'){
                j = i+1;
            }
            else{
                j=i;
            }
            // numerator
            int l= int(expression[j]-'0');
            if(expression[j+1]=='0'){
             numer=numer*10;
             j=j+1;
            }
            numer = l * numer;
             
            
            i = j +2;
            // denomenator
            if (expression[i] == '-') {
                denom = -1;
                j = i + 1;
             } else {
                 j = i;
            }
            
             l = int(expression[j]-'0');
             if(j+1<n && expression[j+1]=='0'){
             denom=denom*10;
             j=j+1;
            }
            denom = l * denom;
            // cout<<numer<<endl;
            // cout<<denom<<endl;
            num.push_back(numer);
            deno.push_back(denom);
            // cout<<expression[i]<<endl;
            i = j;
            // cout<<expression[i]<<endl;
        }
        // finding the  lcm of this numbers 
        // for(int i=0;i<num.size();i++){
        //     cout<<num[i]<<" ";
        // }
        // cout<<endl;
        int ans=deno[0];
        for(int j=1;j<deno.size();j++){
            ans = (((deno[j] * ans)) /
                (gcd(deno[j], ans)));
        }
        int sum=0;
      for(int i=0;i<num.size();i++){
          int d=ans/deno[i];
          sum+= (d* num[i]);
      }
      string finalans;
      if(sum ==0){

        finalans="0/1";
      }
      else if(sum<0){
  
       int sub=gcd(-1*(sum),ans);
       sum=sum*(-1)/sub;
       ans=ans/sub;
    //      cout<<sum<<endl;
    //   cout<<ans<<endl;
       finalans='-' ;
       finalans+= to_string(sum);
       finalans+='/';
       finalans+= to_string(ans);
      }
      else{
         int sub=gcd((sum),ans);
       sum=sum/sub;
       ans=ans/sub;
        cout<<sum<<endl;
      cout<<ans<<endl;
       finalans=to_string(sum);
       finalans+= '/';
       finalans+=to_string(ans);
      }
      return finalans;
    }
}
;