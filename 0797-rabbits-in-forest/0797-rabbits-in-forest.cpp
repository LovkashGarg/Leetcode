class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        int n= answers.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[answers[i]]++;
        }
        int ans=0;
        for(auto i:m){
    
           // means there are some with different color also 
           // for ex -> 0,0,1,1,1
            ans+=ceil(i.second/double(i.first +1 ))*(i.first+1);  // take all of them as separate category


        }

        return ans;

    }
};