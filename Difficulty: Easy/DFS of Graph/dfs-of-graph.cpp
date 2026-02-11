class Solution {
  public:
  
    void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;
        ans.push_back(node);

        for(int next : adj[node]) {
            if(!visited[next]) {
                dfsUtil(next, adj, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<bool> visited(V, false);
        vector<int> ans;

        dfsUtil(0, adj, visited, ans);   // start from node 0

        return ans;
    }
};
