class NumArray {
public:
    vector<int>seq;
    int d;
    void construct (int index,int low ,int  high,vector<int>&nums){
        // means there is only one element 

        if(low==high){
            seq[index]=nums[low];
          return ;
        }

       int mid=(low+ high)/2;

       construct(2*index+1, low,mid,nums);
       construct(2*index+2,mid+1,high,nums);

       seq[index]=seq[2*index+1]+seq[2*index+2];
    }
    NumArray(vector<int>& nums) {
        int n=nums.size();
        seq=vector<int>(4*n);
        int index=0;
        int low=0;
        int high=n-1;
        d=n;
        construct(index,low,high,nums);

        for(int i=0;i<seq.size();i++){
           cout<<seq[i]<<" ";
        }
        cout<<endl;
    }
    int query(int index , int low,int high,int left,int right){


     // No overlap 
     /// low high l r or l r low high
     if(high < left || right <low){
        return 0;
     }

     // complete overlap 
     //left low high right
 
 // iska to sum return kar hi do 
     if(low >=left && high<=right ){
        return seq[index];
     }

     // Partial overlap 
     int mid= (low+ high)/2;
     int l= query(2*index+1, low,mid,left,right);
     int r=query(2*index+2,mid+1, high, left,right);
     return l+ r;
     
    }
    int sumRange(int left, int right) {
        // Now for a query I have 3 cases
        // when no overlap 
        int low=0;
        int high=d-1;
        return query(0,low,high,left,right);

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */