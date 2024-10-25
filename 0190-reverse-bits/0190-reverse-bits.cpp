class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string d="";
         int i = 0;
         int flag=1;
         if(n<0){
            flag-1;
         }
       while (i<32) {

        // storing remainder in binary array
        d+=  char(n % 2 +'0');
        n = n / 2;
        i++;
    }
      long int ans=0;
    for(int i=0;i<32;i++){
        ans =ans*2 +int(d[i]-'0');
    }
        // cout<<ans<<endl;
        return ans*flag;
    }
};