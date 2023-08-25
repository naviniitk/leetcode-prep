class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x:prerequisites) {
            adj[x[0]].push_back(x[1]);
        }

        vector<int> topo; // to store topological order
        vector<int> indegree(numCourses, 0); // to store indegrees of all the vertices
        // calculating the indegrees of all the vertices
        for(int i = 0; i < numCourses; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q; // to perform BFS
        // adding vertices with indegree 0 to the queue
        for(int i = 0; i < numCourses; i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node); // adding the node to topological order
            // reducing the indegree of adjacent vertices and adding them to the queue if their indegree becomes 0
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                }
            }
        }
        if(topo.size() == numCourses) { // if a valid topological order is found, return it
            reverse(topo.begin(), topo.end());
            return topo;
        }
        return {}; // otherwise, return an empty vector
    }
};
