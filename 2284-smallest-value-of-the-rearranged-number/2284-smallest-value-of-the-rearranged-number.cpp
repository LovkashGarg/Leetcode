class Solution {
public:
    long long smallestNumber(long long num) {
      string d=to_string(num);
    //   return 1;
      int flag=1;
      if(num<0){
      d.erase(0,1);
        flag=-1;
      }
      if(flag==1){
      sort(d.begin(),d.end());
      }
      else{
      sort(d.begin(),d.end(),greater<char>());
      }
      cout<<d<<endl;
      int i=0;
       while(i<d.length() && d[i]=='0'){
         i++;
       }
       if(i!=d.length()){
        swap(d[0],d[i]);
       }
       long long int numb=0;
       for(int i=0;i<d.length();i++){
          numb=numb*10 + int(d[i]-'0');
       }
      return numb*flag; 
    }
};