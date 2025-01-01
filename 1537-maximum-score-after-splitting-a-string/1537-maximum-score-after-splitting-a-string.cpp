class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int>zeroes(n);
int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count++;
                zeroes[i]=count;
            }
            else{
                zeroes[i]=count;
            }
        }

    count=0;

    vector<int>ones(n);
    for(int i=n-1;i>=0;i--){
      if(s[i]=='1'){
        count++;
       ones[i]= count;
      }
      else{
        ones[i]=count;
        }
    }

    // now first split 
    // after 0th index 

    int maxi=0;
    for(int i=0;i<n-1;i++){
       maxi=max(maxi,  zeroes[i] + ones[i+1]);
    }
    return maxi;
    }
};