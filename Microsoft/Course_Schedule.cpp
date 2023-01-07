class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        int num= 0,edges = prerequisites.size(),u,v;
        vector<int> indg(numCourses, 0),adj[numCourses];                
    
        for(int i = 0;i<edges;i++){
            u = prerequisites[i][0];
            v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        for(int i=0; i<numCourses; i++)
            for(auto j : adj[i])
                indg[j]++;
        
        for(int i=0; i<numCourses; i++)
            if(indg[i] == 0)
                q.push(i);
       
        while(!q.empty()){
             num++;
            for(int i: adj[q.front()]){
                indg[i]--;
                if(indg[i]==0)
                    q.push(i);
              
            }
            q.pop();
             
        }
        return num == numCourses;
    }
};