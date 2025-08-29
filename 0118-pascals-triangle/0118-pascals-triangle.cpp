class Solution {
public:
    void generator(int row, vector<vector<int>>& res){
        vector<int> rows;
        rows.push_back(1);

        long long ans = 1;
        for(int i = 1; i < row; i++){
            ans *= row-i;
            ans /= i;
            rows.push_back(ans);
        }
        res.push_back(rows);
        return;
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i = 1; i <= n; i++){
            generator(i, ans);
        }
        return ans;
    }
};