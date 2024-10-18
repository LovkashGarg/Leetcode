class Disjoint_set {
public:
    vector<int> parent, size;

    Disjoint_set(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]);  // Path compression
    }

    void unionBysize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] <= size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        if (n == 1) {
            return accounts;
        }

        Disjoint_set ds(n);
        unordered_map<string, int> emailToIndex;

        // Step 1: Union emails based on accounts
        for (int i = 0; i < n; i++) {
            // int deleted = 0;
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                // already present hai element
                if (emailToIndex.count(email)) {
                    int previousIndex = emailToIndex[email];
                    if (previousIndex == i) {
                        // Erase duplicate email within the same account same row me hai
                        accounts[i].erase(accounts[i].begin() + j);
                        // deleted++;
                        j--;  // Stay at the current position after erase
                    } else {
                        // Union two accounts with the same email
                        ds.unionBysize(i, previousIndex);
                    }
                } // first time aa rhe hai
                else {
                    emailToIndex[email] = i;
                }
            }
        }

        // Step 2: Merge accounts based on union-find result
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] != i) {
                for (int j = 1; j < accounts[i].size(); j++) {
                    string email = accounts[i][j];
                    int parentIndex = ds.findPar(i);
                    if (emailToIndex[email] != parentIndex) {
                        if (find(accounts[parentIndex].begin(), accounts[parentIndex].end(), email) == accounts[parentIndex].end()) {
                            accounts[parentIndex].push_back(email);
                        }
                    }
                }
            }
        }

        // Step 3: Erase redundant accounts
        int deleted = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] != i) {
                accounts.erase(accounts.begin() + i - deleted);
                deleted++;
            }
        }

        // Step 4: Sort the emails in each account
        for (int i = 0; i < accounts.size(); i++) {
            sort(accounts[i].begin() + 1, accounts[i].end());
        }

        return accounts;
    }
};
