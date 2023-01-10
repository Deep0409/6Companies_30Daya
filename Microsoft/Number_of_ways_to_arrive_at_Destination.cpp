class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<long long int, long long int>> adj[201];
        vector<long long> distance(201, LLONG_MAX);
        vector<long long> way(201, 0); 
        vector<long long> vis(201, 0);
        priority_queue<pair<long long, long long>,vector<pair<long long, long long>>,greater<pair<long long, long long>>> pq;
        pair<long long, long long> p ;
        int u,v,w;
        long long dist;
        
        
        for(int i = 0; i <roads.size(); i++)
        {
            u = roads[i][0];
            v = roads[i][1];
            w = roads[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
		
        
        pq.push({0, 0});  
        distance[0] = 0; 
        way[0] = 1;
        
        while(!pq.empty())
        {
            p = pq.top(); pq.pop();
            dist = p.first;
            u = p.second;
            
            if(vis[u]) continue;
            
            vis[u] = 1;
          
            for(int i = 0; i < adj[u].size(); i++)
            {
                 v = adj[u][i].first;
                 w = adj[u][i].second;
                
                if(dist + w < distance[v]) 
                {
                    distance[v] = dist + w;
                    pq.push({(dist+w), v});
                    way[v] = way[u];
                }
				
                else if(dist+w == distance[v])
                {
                    way[v] = (way[v] + way[u])%1000000007;
                    pq.push({(dist+w), v});
                }
            }
        }
       
        return (int)way[n-1];
    }
};