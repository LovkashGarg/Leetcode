class Solution {
public:

    void solve(int n,int &power){

       if(n==1){
        return;
       }
       power++;
        if(n%2==0){
            solve(n/2,power);
        }
        else{
            solve(3*n+1,power);
        }
    }
    int getKth(int lo, int hi, int k) {
        

        // Here
        vector<int>ans;
        map<int,int>d;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=lo;i<=hi;i++){
            int power=0;
            solve(i,power);
            pq.push({power,i});      
        }

        
        int i=0;
        while(i<k-1){
            pq.pop();
            i++;
        }

        return pq.top().second;

    }
};