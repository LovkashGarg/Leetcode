class Solution {
public:
    bool findingPossibleorNot(vector< int> & weights,int days,int capacity){
        int count_days=0;
        
        int sum=0;
        for(int i=0;i<weights.size();i++){
             sum+=weights[i];
             if(weights[i] > capacity){
                return false;
             }
             if(sum >capacity){
                cout<<"i"<<i<<endl;
                count_days++;
                i--;
                sum=0;
             }
        }
        if(sum >0){
            count_days+=1;
        }
        cout<<count_days<<endl;
        if(count_days>days){
            return false;
        }
        else{
            return true;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
           int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int low=weights[0];
        int high=sum; 
        int ans=sum;
        while(low<=high){
            // 
            int mid=(low)+(high-low)/2;
            // find out how much container we can carry on each day 
                cout<<"mid"<<mid<<endl;
            if( findingPossibleorNot(weights,days,mid)){
                ans=mid;
                high=mid-1; // try with lower capacity 
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};