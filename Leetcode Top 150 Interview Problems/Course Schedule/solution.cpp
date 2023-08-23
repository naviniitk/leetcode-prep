class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    void build_adj(vector<vector<int>>& prerequisites) {
        for(vector<int>& x:prerequisites) {
            adj[x[1]].push_back(x[0]);
        }
    }

    bool dfs(int i) {
        if(visited[i] == 1)
            return 0;
        if(visited[i] == 2)
            return 1;
        visited[i] = 1;
        for(int j : adj[i]) {
            if(!dfs(j))
                return 0;
        }
        visited[i] = 2;
        return 1;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        build_adj(prerequisites);
        visited.assign(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i])
                if(!dfs(i)) return 0;
        }
        return 1;
    }
};
