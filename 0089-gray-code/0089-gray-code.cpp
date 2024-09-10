class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        for(int i=0;i<(pow(2,n));i++){
            // convering the first number that is 0
            // since there are n bits we can do by
            string graybits;
            int lastbit=0;
            for(int j=1;j<=n;j++){
                // getting the first bit and second last bit 
                int b=(i>>(n-j))%2;
                graybits += ('0' +(b^lastbit));
                lastbit=b;

            }
            int number=0;
     // converting to decimal from binary
     int powe=1;
            for(int j=n-1;j>=0;j--){
               number =number*2 + (graybits[j]-'0');
            }
            ans.push_back(number);
        }
       return ans;
    }
};