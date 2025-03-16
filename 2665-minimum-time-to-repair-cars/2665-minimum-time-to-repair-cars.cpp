class Solution {
public:
bool check(long long minutes, vector<int>&ranks, int cars){
    int n=ranks.size();
    long long total=0;

    for(int i=0;i<n;i++){
     long  double val= floor(sqrt(minutes/double(ranks[i])));
     total+=val;
    }
    if(total >=cars){
        return true;
    }
    return false;
}
    long long repairCars(vector<int>& ranks, int cars) {
       int n=ranks.size();
       int mini=INT_MAX;
       for(int i=0;i<n;i++){
        mini=min(mini, ranks[i]);
       }

       long long low=1;
       long long high=  mini*1ll* cars *cars;
long long ans=high;
       while(low<=high){
        // here mid is the minutes 
        long long mid= (low+ high)/2;

        if(check(mid,ranks,cars)){
            ans=mid;
            high=mid-1;
        }
        else{
            low= mid+1;
        }
       }
       return ans;
    }
};