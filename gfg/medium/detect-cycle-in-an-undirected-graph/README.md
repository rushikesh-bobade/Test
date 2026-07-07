# Undirected Graph Cycle

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an  **undirected graph** with  **V**  vertices and **E** edges, represented as a 2D vector  **edges[][]**, where each entry  **edges[i] = [u, v]**  denotes an edge between vertices  **u**  and  **v**, determine whether the graph contains a  **cycle** or not.

 **Note:**  The graph can have multiple component.

 **Examples:** 

```
Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.

```

```
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.

```

**Constraints:
**1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-07T16:09:34.866Z  

```cpp
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
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)