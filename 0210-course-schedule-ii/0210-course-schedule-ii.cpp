class Solution {
public:
                    //  n --> numCourses
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }

        vector<int> orderOfCourses; // for valid case numberOfCoursesPossible == n aka numberOfCoursesPossible == numCourses 
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            orderOfCourses.push_back(course);

            for(auto neighbouringNodes: adj[course]) {
                indegree[neighbouringNodes]--;
                if(!indegree[neighbouringNodes]) {
                    q.push(neighbouringNodes);
                }
            }
        }
        return orderOfCourses.size() == n ? orderOfCourses : vector<int> {};
    }
};