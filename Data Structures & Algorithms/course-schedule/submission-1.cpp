class Solution {
public:
    using Edges = std::vector<int>;
    using Graph = std::unordered_map<int, Edges>;

    Graph build_Graph(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g;
        // add nodes
        for (int i = 0; i < numCourses; i++) {
            g[i];
        }
        // add the prerequisite edges
        for (int course = 0; course < prerequisites.size(); course++) {
            g[prerequisites[course][0]].push_back(prerequisites[course][1]);
        }
        return g;
    }

    // 0 is white note, 1 is grey node, 2 is black node
    bool dfs(Graph& g, int node, std::vector<int>& visited) {
        visited[node] = 1;
        for (auto c : g[node]) {
            if (visited[c] == 1) {
                return true;
            }
            if (visited[c] == 0 && dfs(g, c, visited)) {
                return true;
            }
        }
        visited[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        Graph g = build_Graph(numCourses, prerequisites);

        // topological sort algorithm/ cycle detection by DFS or BFS
        // DFS on all connected components of a graph with circle detection
        bool flag = false;
        std::vector<int> visited(g.size(), 0);
        for (int i = 0; i < g.size(); i++) {
            if (visited[i] == 0) {
                flag = dfs(g, i, visited);
            }
            // can preemptively finish if atleast one of the nodes has a cycle
            if (flag) {
                return false;
            }
        }
        return true;
    }
};