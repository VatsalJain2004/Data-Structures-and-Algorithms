class Solution {
public:
    bool dfsCheck(int i, vector<int>& vis, vector<int>& pathVis, vector<int>& check, vector<vector<int>>& adj) {
        pathVis[i] = 1, vis[i] = 1, check[i] = 0;

        for(auto it: adj[i]) {
            if(!vis[it]) {
                if(dfsCheck(it, vis, pathVis, check, adj)) {
                    check[i] = 0;
                    return true;
                }
            }
            else if(pathVis[it]) {
                check[i] = 0;
                return true;
            }
        }
        check[i] = 1, pathVis[i] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0), pathVis(n, 0), check(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfsCheck(i, vis, pathVis, check, adj);
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(check[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};