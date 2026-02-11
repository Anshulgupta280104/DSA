class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {

        int v = adj.size();                 // number of vertices
        
        vector<int> visited(v, 0);
        vector<int> ans;
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int j = 0; j < adj[node].size(); j++) {

                int neighbour = adj[node][j];

                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};
