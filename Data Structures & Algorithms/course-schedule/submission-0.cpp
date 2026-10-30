class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /**
            Algo: Graphs (dfs)

            Description: Directed graph problem
            - for cycles, return false
        **/
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0);  // initially 0 (unvisited)

        // iterate edges in adjacency list
        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
        }

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) {
            return false;  // cycle detected
        }

        if (state[node] == 2) {
            return true;  // completed
        }

        state[node] = 1;  // visiting

        for (int v : adj[node]) {
            if (!dfs(v, adj, state)) {
                return false;
            }
        }

        state[node] = 2;  // completed

        return true;
    }
};
