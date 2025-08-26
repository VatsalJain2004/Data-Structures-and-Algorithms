class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        // min heap     // cost, row, col
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int eff = top.first;
            int r = top.second.first;
            int c = top.second.second;
        
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nc >= 0 && nc < m && nr < n){
                    int newEff = max(abs(heights[r][c] - heights[nr][nc]), eff);
                    if(newEff < effort[nr][nc]){
                        effort[nr][nc] = newEff;
                        pq.push({newEff, {nr, nc}});
                    }
                }
            }
        }
        return effort[n-1][m-1] == INT_MAX ? 0 : effort[n-1][m-1];
    }
};