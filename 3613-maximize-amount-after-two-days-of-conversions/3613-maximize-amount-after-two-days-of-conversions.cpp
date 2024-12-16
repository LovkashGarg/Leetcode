class Solution {
public:

    // making the graph
    unordered_map<string,vector<pair<string,double>>>make_graph( vector<vector<string>>& pairs,vector<double>&rates){

        unordered_map<string,vector<pair<string,double>>>graph;

        for(int i=0;i<pairs.size();i++){
            string s1=pairs[i][0];
            string s2=pairs[i][1];
            double cost=rates[i];
            
            graph[s1].emplace_back(s2,cost);
            graph[s2].emplace_back(s1,1.0/cost);
        }

        return graph;
    }
    
    // bfs for finding traversal maximum cost
    unordered_map<string,double>bfs(string initial,unordered_map<string,vector<pair<string,double>>>&graph,double initial_cost=1.0){

        unordered_map<string,double>mp;
        queue<pair<string,double>>q;

        q.push({initial,initial_cost});  // initial 
        mp[initial]=initial_cost;

        while(!q.empty()){
            auto [node,cost]=q.front();
            q.pop();

            for(auto& [new_node,new_cost]:graph[node]){
                double amount=cost*new_cost;
                if(amount>mp[new_node]){
                    q.push({new_node,amount});
                    mp[new_node]=amount;
                }
            }
        }
        return mp;
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        
        auto graph1=make_graph(pairs1,rates1);
        auto graph2=make_graph(pairs2,rates2);

        auto firstamount=bfs(initialCurrency,graph1);

        double maxi=0.0;

        for(auto &[node,cost]:firstamount){
            auto secondamount=bfs(node,graph2,cost);
            maxi=max(maxi,secondamount[initialCurrency]);
        }

        return maxi;

    }
};