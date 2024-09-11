class Solution {
public:
    int getSum(int a, int b) {
        // for 10 bits 
        // int carry=0;
        // for(int i=10;i>=1;i--){
        //    int d1=(a>>(10-i)) %2;
        //    int d2=(b>>(10-i))%2;
        //    cout<<d1<<" "<< d2<<endl; 
        
        //  int bit= d1 ^ d2 ;
        //  cout<<bit<<endl;
        //   if(d1 ==1 && d2==1){
        //     carry=1;
        //  }

        // }
        // checking positive or negative 
        return a+b;

    }
};