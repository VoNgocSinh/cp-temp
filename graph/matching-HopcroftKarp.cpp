struct maximumMaching {

    vector<int> x, y, cnt, q;
    vector<vector<int>> edge;
    int n;
    int INF;

    maximumMaching(int _n) {

        n = _n;
        INF = 1e9;
        x = y = cnt = q = vector<int>(n + 1, 0);
        edge = vector<vector<int>>(n + 1);        
    }

    void addEdge(int u, int v) {edge[u].push_back(v);}

    bool findpath() {

        int l = 1;
        int r = 0;

        for (int u = 1; u <= n; ++u)
            if (!x[u]) {

                    cnt[u] = 0;
                    q[++r] = u;
                }
                else cnt[u] = INF;

        cnt[0] = INF;

        while (l <= r) {

                int u = q[l++];

                for (int v : edge[u])
                    if (cnt[y[v]] == INF) {
                            cnt[y[v]] = cnt[u] + 1;
                            if (y[v]) q[++r] = y[v];
                        } 
            }

        return cnt[0] != INF;
    }

    bool dfs(int u) {

        for (int v : edge[u]) {

                if (y[v] == 0)  {

                        x[u] = v;
                        y[v] = u;
                        cnt[u] = INF;
                        return 1;
                    
                    }
                
                if (cnt[y[v]] == cnt[u] + 1)
                    if (dfs(y[v])) {

                            x[u] = v;
                            y[v] = u;
                            cnt[u] = INF;
                            return 1;
                        
                        }
            }

        cnt[u] = INF;
        return 0;

    }

    void match() {

        int res = 0;

        while(findpath()) {

            for (int u = 1; u <= n; ++u) 
                if (!x[u] && dfs(u)) ++res;
        }

        cout << res << '\n';
        // for (int i = 1; i <= n; i++)
        //     if (x[i])
        //         cout << i << ' ' << x[i] << '\n';
    }
};