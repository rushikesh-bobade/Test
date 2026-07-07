                if (dfs(neighbor, node, adj, vis))
                    return true;
            }
            else if (neighbor != parent) {
                return true; // Found a back edge => cycle
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        // Check all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};