class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

         vector<int> indegree(numCourses, 0);

        vector<vector<int>> adj(numCourses);

        for(auto& pre: prerequisites){
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;

        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int neighbour: adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        if(ans.size() == numCourses)
        return ans;

        else return {};

        
    }
};