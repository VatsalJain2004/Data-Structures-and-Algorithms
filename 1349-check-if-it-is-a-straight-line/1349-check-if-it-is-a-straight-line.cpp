class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // using slope = (y2-y1)/(x2-x1)  --> Denominator can be 0 hence we will implement it as cross-multipy
        int n = coordinates.size();
        if(n <= 2) {
            return true;
        }

        for(int i = 0; i < n-2; i++) {
            int x0 = coordinates[i][0], y0 = coordinates[i][1];
            int x1 = coordinates[i+1][0], y1 = coordinates[i+1][1];
            int x2 = coordinates[i+2][0], y2 = coordinates[i+2][1];
            int left = (y2-y0)*(x1-x0), right = (y1-y0)*(x2-x0);
            if(left != right) {
                return false;
            }
        }
        return true;
    }
};