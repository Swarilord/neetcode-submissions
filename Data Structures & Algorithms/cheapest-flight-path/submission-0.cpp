//assume standard headers and using namespace std
class Solution {
public:
    struct Edge{
        int to;
        int weight;
    };

    using Graph = vector<vector<Edge>>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //build Graph
        Graph g(n);
        for(auto flight: flights){
            g[flight[0]].push_back({flight[1], flight[2]});
        }
        //bellman ford k
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        vector<int> temp(n, INT_MAX);
        int to;
        int price;
        for(int i = 0; i < k + 1; i++){
            temp = dist;
            for(int from = 0; from < (int)g.size(); from++){
                for(auto& edge: g[from]){
                    to = edge.to;
                    price = edge.weight;
                    if(dist[from] == INT_MAX){
                        continue;
                    }
                    if(dist[from] + price < temp[to]){
                        temp[to] = dist[from] + price;
                    }
                }
            }
            dist = temp;
        }
        //return distances
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};
