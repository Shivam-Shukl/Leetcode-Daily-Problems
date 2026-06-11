class Solution {
public:

    void depth(unordered_map<int, vector<int>>& adj,
               vector<bool>& vis,
               int curr,
               int source,
               int& ans) {

        ans = max(ans, curr);
        vis[source] = true;

        for (int ele : adj[source]) {
            if (!vis[ele]) {
                depth(adj, vis, curr + 1, ele, ans);
            }
        }
    }

    long long power(long long base, long long exp, long long mod) {
        long long res = 1;

        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % mod;

            base = (base * base) % mod;
            exp >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        
        const int MOD = 1000000007; 

        int n = edges.size() + 1;
        vector<bool> vis(n + 1, false);

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);   
        }

        int ans = 0;    
        depth(adj, vis, 0, 1, ans);

        
        if (ans <= 1)
            return 1;
        else
            return (int)power(2, ans - 1, MOD);
    }
};