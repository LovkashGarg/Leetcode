class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
             int n=potions.size();
vector<int> ans;
        for(int i=0;i<spells.size();i++){

             int low=0;
             int high= potions.size()-1;
             int number=0;
             while(low<=high){
                 int mid=low + (high-low)/2;

                 if((1LL*potions[mid])*(1LL* spells[i]) <success){
                    low=mid+1;
                 }
                 else {
                    number=(n-mid);
                    high=mid-1;
                 }
             }
            //  cout<<number<<endl;
             ans.push_back(number);

        }
        return ans;
    }
};