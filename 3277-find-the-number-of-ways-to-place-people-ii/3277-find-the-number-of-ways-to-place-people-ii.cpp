class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        
        auto lambda = [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] > b[1]; 
            }
            return a[0] < b[0]; 
        };
        sort(points.begin(), points.end(), lambda);
        
        for(int i = 0; i < n; i++) {
            int xi = points[i][0];
            int yi = points[i][1];

            int maxY = INT_MIN;
            for(int j = i+1; j < n; j++) {
                int xj = points[j][0];
                int yj = points[j][1];
                
                if(yj > yi) {
                    continue;
                }
                if(yj > maxY) {
                    result += 1;
                    maxY = yj;  
                }
            }   
        }
        return result;
    }
};