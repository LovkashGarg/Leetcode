class Solution {
public:
    int numberOfSubstrings(string s) {

    // we are trying to work on the logic that the 
    // with every character that ends there is a substring that ends


      int lastseena=-1;
      int lastseenb=-1;
      int lastseenc=-1;
int countsubstring =0;
      for(int i=0;i< s.length();i++){

        
           if(s[i]=='a'){
            lastseena=i;
           }
           else if(s[i]=='b'){
            lastseenb=i;
           }
           else{
            lastseenc=i;
           }


           if(lastseena !=-1 && lastseenb!=-1 && lastseenc!=-1){
            int minindexstart= min(lastseena, min(lastseenb, lastseenc));
            // one is the window itself and rest are the string consisting of left elements
                 countsubstring+= (minindexstart +1);
           }

      }
      return countsubstring;
    }
};