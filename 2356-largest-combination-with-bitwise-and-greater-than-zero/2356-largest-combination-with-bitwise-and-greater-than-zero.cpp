class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
      

// for each bit I have to find the number of number which have the set bit as one
int finalans=0; 
int count;
for(int i=0;i<24;i++){
   // 
   count=0;
    // cout<<(1<<i)<<endl;
   for(int j=0;j<candidates.size();j++){
    // check if the number is not equal to zero 
     if((candidates[j]&(1<<i))!=0){
        // cout<<(1<<i)<<" "<< candidates[j]<<endl;
        count++;
     }
    }
     finalans=max(finalans,count);
}
return finalans;
    }
};