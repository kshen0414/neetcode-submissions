class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        /**
            Algo: Graphs - DFS

            Knowledge: Undirected graph means connections work both ways

        **/

        int componentCount = 0;

        vector<bool> visited(n, false);

        // initialize an adjacency list
        vector<vector<int>> adj(n);

        // iterate edges in adjacency list
        for (const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++){
            if (!visited[i]){
                componentCount++;
                dfs(i, adj, visited);
            }
        }

        return componentCount;

    }

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;

        for (int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited);
            }
        }
    }
};
