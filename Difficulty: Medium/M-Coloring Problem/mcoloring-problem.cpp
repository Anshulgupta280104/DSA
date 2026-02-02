class Solution {
public:

    bool isSafe(int node, int col, vector<int>& color, vector<vector<int>>& graph, int v) {
        for(int k = 0; k < v; k++) {
            if(graph[node][k] == 1 && color[k] == col)
                return false;
        }
        return true;
    }

    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph, int m, int v) {

        // all nodes colored
        if(node == v) return true;

        // try all colors
        for(int c = 0; c < m; c++) {

            if(isSafe(node, c, color, graph, v)) {

                color[node] = c;

                if(dfs(node + 1, color, graph, m, v))
                    return true;

                // backtrack
                color[node] = -1;
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {

        // build graph matrix
        vector<vector<int>> graph(v, vector<int>(v, 0));

        for(auto &e : edges) {
            graph[e[0]][e[1]] = 1;
            graph[e[1]][e[0]] = 1;
        }

        vector<int> color(v, -1);

        return dfs(0, color, graph, m, v);
    }
};
