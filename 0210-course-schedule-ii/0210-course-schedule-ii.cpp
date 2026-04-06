class Solution {
public:
    vector<int> findOrder(int V , vector<vector<int>>& pre) {
        // 
        vector<vector<int>> graph(V);
        vector<int> ind(V,0);
        for(int i =0;i<pre.size();i++){
            int u = pre[i][0];
            int v = pre[i][1];
            graph[v].push_back(u);
            ind[u]++;
        }
        
        queue<int> q;
        for(int i = 0;i<V;i++){
            if(ind[i] ==0){
                q.push(i);
            }
        }

        vector<int> val;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            val.push_back(frontNode);
            for(auto u : graph[frontNode]){
                ind[u]--;
                if(ind[u] == 0){
                    q.push(u);
                }
            }
        }

        return (val.size() == V) ? val : vector<int>{};

    }
};