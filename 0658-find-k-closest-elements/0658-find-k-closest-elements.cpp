class Solution {
public:
   class customCompartor{
    public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
         if(a.first== b.first){
            return a.second>=b.second;
         }
         return a.first>b.first;
    }
   };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,customCompartor>q;
        int n=arr.size();
        for(int i=0;i<n;i++){
            q.push({abs(arr[i]-x),i});
        }
       vector<int> ans(k);
       int i=0;
        while(!q.empty()){
        //   cout<<q.top().first<<q.top().second<<endl;
        //   cout<<i<<endl;
          ans[i]=arr[q.top().second];
          i++;
          if(i==k){
            break;
            }
          q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};