class Solution {
public:
    int nextGreaterElement(int l) {
       
       
        string d=to_string(l);
        // cout<<d<<endl;
        int n=d.length();

        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=int(d[i]-'0');
        }
        int index=-1;       
         for(int i=n-2;i>=0;i--){
            if(ans[i]<ans[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            return -1;
        }

        for(int i=n-1;i> index;i--){
            if(ans[i]> ans[index]){
                swap(ans[i],ans[index]);
                break;
            }
       }
    
      reverse(ans.begin()+ index+1, ans.end());
       
      long long int numb= 0;

      for(int i=0;i< n;i++){
        // cout<<ans[i]<<" ";
        numb=numb*10 + ans[i];
      }
      if(numb >INT_MAX){
        return -1;
      }
    //    cout<<endl;
    //     cout<<INT_MAX<<endl;
    //   if(numb )
    //   cout<<s<<endl;
      return numb;
    }
};