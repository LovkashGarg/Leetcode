class Disjoint_set {
public:
    vector<int> parent;
    vector<int> size;

    Disjoint_set(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        } else {
            return parent[node] = findPar(parent[node]);
        }
    }
    void unionBysize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v) {
            return;
        } else {
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint_set ds(n);
        // traverse through all the edges
        int count = 0;

        for (auto i : connections) {
            int u = i[0];
            int v = i[1];

            // means redundant edge therefore can be removed;
            if (ds.findPar(u) == ds.findPar(v)) {
                count++;
            }else{
                ds.unionBysize(u,v);
            }
        }
        // check no of component
        int cop = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                cop++;
            }
        }
        // cout << cop << " " << count << endl;
        if (cop - 1 <= count) {
            return cop-1;
        }
        return -1;
    }
};