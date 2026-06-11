class Solution {
public:
    // Pass 'parent' instead of a 'vis' array
    void depth(vector<vector<int>>& adj, int curr, int source, int parent, int& ans) {
        ans = max(ans, curr);

        for (int ele : adj[source]) {
            if (ele != parent) { // Only skip if it's the node we just came from
                depth(adj, curr + 1, ele, source, ans);
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
        
        // Optimization: Use a vector of vectors instead of unordered_map
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);   
        }

        int ans = 0;    
        // 0 is the initial depth, 1 is the source node, -1 is the dummy parent
        depth(adj, 0, 1, -1, ans);

        if (ans <= 1)
            return 1;
        else
            return (int)power(2, ans - 1, MOD);
    }
};