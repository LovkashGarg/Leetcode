class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int low=0;
        int n= letters.size();
        int high=n-1;
        char ans=char(127);
        while(low<=high){
            int mid= (low+high)/2;
            if(letters[mid] >target){
                ans=min(ans,letters[mid]);
                high=mid-1;
            }
            else{
low= mid+1;
            }
        }

        if(ans== char(127)){
            return letters[0];
        }
        else{
            return ans;
        }
    }
};