class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int ans=INT_MAX;
        int countwhite=0;
        for(int i=0;i<k-1;i++){
if(blocks[i]=='W'){
    countwhite++;
}
        }

       
       
        int n=blocks.size();

        for(int i=k-1;i<n;i++){
 
            if(blocks[i]=='W'){
                countwhite++;
            }
        //   int totalblack= k-countwhite;
           ans=min(ans,countwhite);
           if(blocks[i-k+1]=='W'){
            countwhite--;
           }
           
        }
        
        return ans;
    }
};