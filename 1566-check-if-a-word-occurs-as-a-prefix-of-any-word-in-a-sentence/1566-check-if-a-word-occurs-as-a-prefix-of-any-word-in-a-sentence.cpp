class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int i=1; // word count 
        int j=0; // sentence curr index 
        int n1=sentence.size();
        int n2=searchWord.size();
        while(j<n1){
           
           // note the starting index 
           int start=j;
           int k=0; // my index of searchWord 
           while(j < n1 && sentence[j]!=' '){
            if(k<n2 && sentence[j] == searchWord[k] ){
                k++;
            }
            
            j++;
            // second condition to check if the starting point is same 
             if(k==n2 && j-start== n2 ){  
            return i;
           }
           }

           j++;
           i++;

        }

        return -1;
    }
};