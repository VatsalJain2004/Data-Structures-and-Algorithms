// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int j = 0; j < V-1; j++) {
            for(auto &e: edges) {
                int node = e[0], adjNode = e[1], weight = e[2];
                if(dist[node] != 1e8 && dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                }
            }
        }
        
        for(auto &e: edges) {
            int node = e[0], adjNode = e[1], weight = e[2];
            if(dist[node] != 1e8 && dist[node]+weight < dist[adjNode]) {
                return {-1};
            }
        }
        return dist;
    }
};
