class Solution {
public:
void FastIO()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
}

    long long pickGifts(vector<int>& gifts, int k) {
        FastIO();
        priority_queue<int>pq;
        int n=gifts.size();
        for(int i=0;i<n;i++){
pq.push(gifts[i]);
        }

        int i=1;
        while(i<=k){
            auto maxi=pq.top();
            pq.pop();
            int topush=floor(sqrt(maxi));
            pq.push(topush);

            i++;
        }
       long long  int total=0;
        while(!pq.empty()){
            total+=pq.top();
            pq.pop();
        }
        return total;
    }
};