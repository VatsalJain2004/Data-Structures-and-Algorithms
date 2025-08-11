// class Solution {
// public:
//                     //  n --> numCourses
//     vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(n);
//         for(auto it: prerequisites) {
//             adj[it[0]].push_back(it[1]);
//         }

//         vector<int> indegree(n, 0);
//     for(int i = 0; i < n; i++) {
//             for(auto it: adj[i]) {
//                 indegree[it]++;
//             }
//         }

//         queue<int> q;
//         for(int i = 0; i < n; i++) {
//             if(!indegree[i]) {
//                 q.push(i);
//             }
//         }

//         vector<int> orderOfCourses; // for valid case numberOfCoursesPossible == n aka numberOfCoursesPossible == numCourses 
//         while(!q.empty()) {
//             int course = q.front();
//             q.pop();
//             orderOfCourses.push_back(course);

//             for(auto neighbouringNodes: adj[course]) {
//                 indegree[neighbouringNodes]--;
//                 if(!indegree[neighbouringNodes]) {
//                     q.push(neighbouringNodes);
//                 }
//             }
//         }
//         return orderOfCourses;
//     }
// };

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<int> adj[N];
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        //TOPOLOGICAL SORT CODE
        vector<int> indegree(N, 0);
        
        for(int i = 0; i < N; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }   
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(topo.size() == N)
            return topo;
        return {};
        // return topo.size() == N ? topo : vector<int>{};
    }
};