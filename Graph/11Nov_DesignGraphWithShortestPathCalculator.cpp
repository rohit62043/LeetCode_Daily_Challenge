class Graph {
public:
    vector<vector<pair<int, int>>> adjacencyList;
    
    Graph(int n, vector<vector<int>>& edges) {
        adjacencyList.resize(n);
        for(auto edge:edges){
        
            adjacencyList[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjacencyList[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
       set<pair<int,int>> st; 

        // Initialising dist list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> dist(1000, 1e9); 
        int S=node1;
        st.insert({0, S}); 

        // Source initialised with dist=0
        dist[S] = 0;
        
        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for(auto it : adjacencyList[node]) {
                int adjNode = it.first; 
                int edgW = it.second; 
                
                if(dis + edgW < dist[adjNode]) {
                    // erase if it was visited previously at 
                    // a greater cost.
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                        
                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
        return dist[node2]!=1e9?dist[node2]:-1;

    }
};
