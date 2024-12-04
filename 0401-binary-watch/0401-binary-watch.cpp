class Solution {
public:
    void solve(vector<string>&ans,int turnedOn,int index,vector<int>time ){
       
       if(index==10){
        // calculate time 
        if(turnedOn==0){
int hour=0;
       int t=1;
        for(int i=3;i>=0;i--){
        hour=hour+time[i]*t;
        t=t*2;
        }
        t=1;
        int min=0;
        for(int i=9;i>=4;i--){
          min=min+ time[i]*t;
          t=t*2;
        }

        if(hour >=0 && hour <= 11  && min >=0 && min <=59){
            string hours=to_string(hour);
            string d=hours;
            d+=':';

            string mins=to_string(min);
            if(min <=9){
                mins='0'+ mins;
            }
            d+=mins;
            ans.push_back(d); 
        }
        }
        return;
       }
       
       time[index]=1;
       solve(ans,turnedOn-1,index+1,time);
       time[index]=0;

       solve(ans,turnedOn,index+1,time);

    }
    vector<string> readBinaryWatch(int turnedOn) {


       vector<string>ans;
       vector<int>time(10,0);
       int index=0;
       solve(ans,turnedOn,index,time);
       return ans;

    }
};