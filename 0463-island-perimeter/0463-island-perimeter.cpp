class Solution {
public:
    int n, m;
    
    int dfs(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
            return 1; 
            
        if(grid[r][c] == -1) {
            return 0;
        }
        grid[r][c] = -1;
        return dfs(r, c-1, grid) + dfs(r, c+1, grid) + dfs(r-1, c, grid) + dfs(r+1, c, grid);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]) {
                    ans += dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};






















// class Solution{
// public:
//     int islandPerimeter(vector<vector<int>>& grid){
//         int perimeter = 0;
//         int rows = grid.size(), cols = grid[0].size();
        
//         for(int r = 0; r < rows; r++){
//             for(int c = 0; c < cols; c++){
//                 if(grid[r][c] == 1){
//                     perimeter += 4;
//                     if(r > 0 && grid[r-1][c] == 1){
//                         perimeter -= 2;
//                     }
//                     if(c > 0 && grid[r][c-1] == 1){
//                         perimeter -= 2;
//                     }
//                 }
//             }
//         }
        
//         return perimeter;
//     }
// };











// class Solution{
// public:
//     int rows, cols;
    
//     int islandPerimeter(vector<vector<int>>& grid){
//         rows = grid.size(), cols = grid[0].size();
//         int perimeter = 0;
//         for(int r = 0; r < rows; r++){
//             for(int c = 0; c < cols; c++){
//                 if(grid[r][c] == 1){
//                     perimeter += dfs(grid, r, c);
//                 }
//             }
//         }
//         return perimeter;
//     }

// private:
//     int dfs(vector<vector<int>>& grid, int r, int c){
//         if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) 
//             return 1;
//         if(grid[r][c] == -1)    return 0;

//         grid[r][c] = -1;

//         return(dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + 
//                         dfs(grid, r, c + 1) + dfs(grid, r, c - 1));
//     }
// };