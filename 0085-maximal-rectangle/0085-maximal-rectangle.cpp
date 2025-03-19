class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();

        vector<int>prevcol(m,0);
        vector<int>currcol(m,0);

    int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    currcol[j]=0;
                }
                else{
                    currcol[j]=prevcol[j]+1;
                }
            }
             
             stack<int>s;
            vector<int>pse(m);
             for(int k=0;k<m;k++){
                // agar andar vala bda hai to use nikal do 
              while(!s.empty() && currcol[k] <= currcol[s.top()]){
              // means we have got the nse element for this element
              maxarea=max(maxarea, currcol[s.top()] *(k-pse[s.top()]-1) );
              s.pop();

              }

              if(s.empty()){
                pse[k]=-1;
              }
              else{
                pse[k]=s.top();
              }

              s.push(k);

             }
            
            while(!s.empty()){
                int topIndex = s.top();
                s.pop();
                int width = m - (s.empty() ? -1 : s.top()) - 1;
                maxarea = max(maxarea, currcol[topIndex] * width);
            }
            
            prevcol=currcol;

        }
        return maxarea;
    }
};