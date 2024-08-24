class Solution {
public:
    int findBouqetsformed(vector<int>& bloomDay,int mid, int m, int k){
        int n=bloomDay.size();
        vector<int> copiedbloomDay(bloomDay.begin(),bloomDay.end());
        for(int i=0;i<n;i++){
          if(bloomDay[i]<=mid){
            copiedbloomDay[i]=0; // 0 means it is bloomed 
          }
        }

        // check no of bouqets formed 
        int j=0;
        int bouqets=0;
        cout<<"Starting "<<endl;
        while(j<n){
            // means 
            if(copiedbloomDay[j]==0){
               int count=0;
               while(j<n && copiedbloomDay[j]==0 && count<k){
               count++;
               j++;
               }
               if(count==k){
                bouqets++;
                cout<<"ending" <<j<<endl;
                continue;
               }
            }
            j++;
        }
        return bouqets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(long(m)*k >n){
            return -1; // not possible 
        }
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            maxi=max(maxi,bloomDay[i]);
        }
        // maxi is the number of days max it could take 
        int low=1;
        int high=maxi;
        int ans=maxi;
        while(low<=high){
            int mid=(low)+ (high-low)/2;
              cout<<mid<<endl;
            int noofbouqets=findBouqetsformed(bloomDay,mid,m,k);
            cout<<noofbouqets << mid<<endl;
            if(noofbouqets<m){
              low=mid+1; // means we require more days 
            }
            else{
                ans=mid;
                high=mid-1; // check if there are possible lesser ways to make bouqets 
            }
        }
        return ans;
    }
};