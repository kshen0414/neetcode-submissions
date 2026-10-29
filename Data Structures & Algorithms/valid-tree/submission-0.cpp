class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /**
            Algo: Graphs
            Definition:
            - Connected (every node can be reached from every other node)
            - No cycles

            Constraints: No self loops or repeated edges
            Additional Info: edges are undirected

            hint: edges are always n - 1

        **/

        vector<bool> visited(n, false);

        vector<vector<int>> adj(n);

        // edge case: not valid graph
        if (edges.size() != n - 1) {
            return false;
        }

        // iterate edges in adjacency list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // call dfs
        dfs(0, adj, visited);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;  // was not visited
            }
            
        }

        return true;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }
};
