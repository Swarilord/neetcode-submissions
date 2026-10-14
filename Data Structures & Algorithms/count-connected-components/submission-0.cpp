class Solution {
public:

    void dfs(int node, std::vector<bool>& visited, std::unordered_map<int, vector<int>>& graph){
        visited[node] = true;
        for(auto neigh: graph[node]){
            if(!visited[neigh]){
                dfs(neigh, visited, graph);   
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        //build graph of edges between each nodes 
        //go through each connected component of the graph with a dfs 
        std::unordered_map<int, vector<int>> graph;
        std::vector<bool> visited(n, false);
        int count = 0;
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++){
            if(visited[i]){
                continue;
            }
            dfs(i, visited, graph);
            count++;
        }
        return count;
    }
};
