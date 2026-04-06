class Solution {
public:
    bool isSafe(int node, vector<vector<int>>& graph, vector<bool>& safeNode, vector<bool>& vis) {
       
        if (safeNode[node]) return true;
        
        if (vis[node]) return false;

        vis[node] = true;

        for (auto j : graph[node]) {
       
            if (!isSafe(j, graph, safeNode, vis)) {
                return false; 
            }
        }

        safeNode[node] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> safeNode(n, false);
        vector<bool> vis(n, false);
    
        // Run DFS from every unvisited node
        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                isSafe(j, graph, safeNode, vis);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safeNode[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};