class NumArray {
public:
    vector<int>seg;
    int d;
    void construct(int index,int low,int high ,vector<int> & nums){
        if(low==high){
         seg[index]=nums[low];
         return;
        }
        int  mid= (low+ high)/2;
         construct(2*index+1,low,mid,nums);
        construct(2*index+2,mid+1,high,nums);
        seg[index]= seg[2*index+1]+seg[2*index+2];

    }
    NumArray(vector<int>& nums) {
        int n=nums.size();
     seg=vector<int>(4*n);
     int index=0;
     int low=0;
     d=n;
     int high=n-1;
     construct(index,low,high,nums);

    }
     void updateUtil(int index,int low,int high,int i,int val ){
        // since we are going left and right in search of our range 
        if(low==high){
            seg[index]=val;
            return;
        }

        // now since the index of the element to be changed is i 
        // 
        int mid=(low+ high)/2;
        // matlab left side me jao update karne 
        if(i<= mid){
          updateUtil(2*index+1, low,mid,i,val);
        }
        else{
           updateUtil(2*index+2,mid+1,high,i,val); 
        }
        seg[index]= seg[2*index+1]+ seg[2*index+2];
     }
    void update(int i, int val) {
        // to update we have to do 
        int index=0;
        int low=0;
        int high=d-1;
        updateUtil(index, low,high, i,val);
    }
     int query(int index,int low,int high,int left,int right){
        // no overlap low high l r  l r low high 
        if( left > high || low > right){
            return 0;
        }

        // complete overlap left low high right 
        if(left <= low && high <= right){
            return seg[index];
        }

        int mid= (low+ high)/2;

         // partial overlap 
         // go on both sides
          int l= query(2* index +1, low,mid , left,right);
          int r= query(2*index+2, mid+1, high, left, right);
          return l+r;

        
     }
    int sumRange(int left, int right) {
          int index=0;
          int low=0;
          int high=d-1;
        return query(index, low,high,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */