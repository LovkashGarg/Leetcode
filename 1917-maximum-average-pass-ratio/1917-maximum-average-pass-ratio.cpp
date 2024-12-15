class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double,double>> pq;

        int n=classes.size();

        // after one extra student and  previously 
        for(int i=0;i<n;i++){
            pq.push({(double(classes[i][0]+1)/(classes[i][1]+1))-(double(classes[i][0])/(classes[i][1])),i });
        }

        int dep=0;
     
        while(dep<extraStudents){
             // larger the difference in change more we can
          auto change=pq.top().first;
          auto index=pq.top().second;
          pq.pop();

          classes[index][0]++;
          classes[index][1]++;
         pq.push({double(classes[index][0]+1)/double(classes[index][1]+1) -  double(classes[index][0])/double(classes[index][1])  ,index});
          dep++;
        }

        double sum=0;

        for(int i=0;i<n;i++){
         sum+= (double (classes[i][0])/ double(classes[i][1]));
        }

        return sum/double(n);

    }
};