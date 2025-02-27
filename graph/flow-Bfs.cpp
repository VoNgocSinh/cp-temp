struct maximumFlow {
 
    vector<int> idEdge[N];
    int trace[N];
    int s, t;
    int maximumflow;

    struct flowEdge {

        int u, v, flow;

    };

    vector<flowEdge> edge;

    maximumFlow () {
 
        maximumflow = 0;
 
    }
 
    void updateSourceSink(int source, int sink) {
 
        s = source;
        t = sink;
 
    }
 
    void addEdge(int u, int v, int c) {
 
        flowEdge Edge;

        Edge = {u, v, c};
        edge.push_back(Edge);
        idEdge[u].push_back(edge.size() - 1);

        Edge = {v, u, 0};
        edge.push_back(Edge);
        idEdge[v].push_back(edge.size() - 1);

    }
 
    void bfs(int u) {

        queue<int> q;
        q.push(u);

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int x : idEdge[u])
                if (trace[edge[x].v] == -1 && edge[x].flow) {
    
                    trace[edge[x].v] = x;
                    q.push(edge[x].v);
    
                }

        }

    }
 
    bool increaseFlow() {
 
        for (int i = 1; i <= n; i++)
            trace[i] = -1;
        trace[s] = 0;
 
        bfs(s);

        if (trace[t] == -1)
            return false;
 
        vector<int> V;
 
        int increase = INF;

        int sink = t;
        while (sink != s) {
 
            minimize(increase, edge[trace[sink]].flow);
            V.push_back(trace[sink]);
            sink = edge[trace[sink]].u;

        }

        for (int x : V) {

            edge[x].flow -= increase;
            edge[x ^ 1].flow += increase;

        }
 
        maximumflow += increase;
 
        return increase;
 
    }
 
    int Maching() {
 
        do {
 
            if (!increaseFlow()) 
                break;
 
        } while (true);
 
        return maximumflow;
 
    }
 
} flow;
