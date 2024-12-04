class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
      int i=0;
      int j=0;
      int n=str1.size();
      int m=str2.size();

     // TimeComplexicity is 0(n)
      while(i<n && j< m){
        // cout<< str1[i] <<" "<<str2[j]<<endl;
       if(str2[j] =='a' && str1[i]=='z'){
        i++;
        j++;
       }
       else if(str2[j]-str1[i] ==1 || str2[j]-str1[i]==0){
        i++;
        j++;
       }
       else{
        // matlab isse to nhi hoga 
        i++;
       }
      }
      if(j==m){
        return true;
      }
      else{
        return false;
      }

    }
};