class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>s;
        int n= heights.size();
       vector<int>ans(n);
    
        for(int i=n-1;i>=0;i--){

           int count=1;
            // maintain a increasing stack 
           while(!s.empty() && heights[i] >= heights[s.top()]){
            s.pop();
            count++;
           }
           // agar kuch bna nhi to vo last element hoga so dont count the next element after it treat count as 0 
           if(s.empty()){
           ans[i]=count-1; 
           }
           else{
            ans[i]=count;
           }

           s.push(i);
        }

        return ans;
    }
};