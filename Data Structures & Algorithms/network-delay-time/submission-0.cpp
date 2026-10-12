using namespace std;
class Solution {
public:
    struct Edge{
        int to;
        int weight;
    };
    using Graph = vector<vector<Edge>>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //build Graph
        Graph g(n + 1);
        int src, trgt, ti;
        for(int i = 0; i < times.size(); i++){
            src = times[i][0];
            trgt = times[i][1];
            ti = times[i][2];
            g[src].push_back({trgt, ti});
        }
        //findest shortest path from src to all other nodes
        std::vector<int> dist(n + 1, INT_MAX);
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]){
                continue;
            }
            for(auto ngb: g[u]){
                int to = ngb.to;
                int w = ngb.weight;
                
                if(dist[to] > w + dist[u]){
                    dist[to] = w + dist[u];
                    pq.push({dist[to], to});
                }
            }
        }

        int max = 0;
        for(int i = 1; i < dist.size(); i++){
            max = std::max(max, dist[i]);
        }

        if(max == INT_MAX){
            return -1;
        }
        return max;
    }
};
