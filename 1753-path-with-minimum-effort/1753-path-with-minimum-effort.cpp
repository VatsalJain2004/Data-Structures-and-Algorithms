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




// class Solution {
// private:
//     vector<int> dirs = {0, 1, 0, -1, 0};

//     bool isValid(int row, int col, int rows, int cols) {
//         return row >= 0 && col >= 0 && row < rows && col < cols;
//     }
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int rows = heights.size(), cols = heights[0].size();
//         vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
//         priority_queue<pair<int, pair<int, int>>> pq;
//         pq.push({0, {0, 0}});
//         distance[0][0] = 0;
//         while (!pq.empty()) {
//             auto curr = pq.top();
//             pq.pop();
//             int currDistance = -1 * curr.first;
//             int currRow = curr.second.first;
//             int currCol = curr.second.second;
//             if (currRow == rows - 1 && currCol == cols - 1) {
//                 return currDistance;
//             }
//             for (int index = 0; index < 4; index++) {
//                 int nextRow = currRow + dirs[index];
//                 int nextCol = currCol + dirs[index + 1];
//                 if (isValid(nextRow, nextCol, rows, cols)) {
//                     int nextDistance = max(currDistance, abs(heights[nextRow][nextCol] - heights[currRow][currCol]));
//                     if (nextDistance < distance[nextRow][nextCol]) {
//                         pq.push({-1 * nextDistance, {nextRow, nextCol}});
//                         distance[nextRow][nextCol] = nextDistance;
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };



// class Solution {
//   public:
//     int minimumEffortPath(vector<vector<int>> &height) {
//         int n = height.size(), m = height[0].size(); 
//         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
//         pq.push({-1e9, {0, 0}});
        
//         vector<vector<int>> effort(n, vector<int>(m, 1e9));
//         effort[0][0] = 0;
        
//         int dr[] = {0, 1, 0, -1};
//         int dc[] = {1, 0, -1, 0};
//         while(!pq.empty()){
//             auto top = pq.top();
//             pq.pop();
//             int eff = top.first;
//             int r = top.second.first;
//             int c = top.second.second;
            
//             // if(r == n-1 && c == m-1)
//             //     return eff;
            
//             for(int i = 0; i < 4; i++){
//                 int nr = r + dr[i];
//                 int nc = c + dc[i];
                
//                 if(nr >= 0 && nc >= 0 && nr < n && nc < m){
//                     int newEff = max(abs(height[nr][nc] - height[r][c]), eff);
//                     if(newEff < effort[nr][nc]){
//                         effort[nr][nc] = newEff;
//                         pq.push({newEff, {nr, nc}});
//                     }
//                 }
//             }
//         }
//         return effort[n-1][m-1];
//     }
// };