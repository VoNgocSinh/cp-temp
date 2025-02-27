const int LOGN = 19;
int Par[N][LOGN], h[N];
struct LowestCommonAncestor {

    void dfs(int u, int par) {

        Par[u][0] = par;
        h[u] = h[par] + 1;
        for (int x : edge[u])
            if (par != x)
                dfs(x, u);
    }

    void prepare(int root) {

        dfs(root, root);
        for (int j = 1; j < LOGN; j++)
            for (int i = 1; i <= n; i++)
                Par[i][j] = Par[Par[i][j - 1]][j - 1];
    }

    int lca(int u, int v) {

        if (h[u] > h[v])
            swap(u, v);

        for (int j = LOGN - 1; j >= 0; j--)
            if ((h[v] - (1 << j)) >= h[u])
                v = Par[v][j];

        if (u == v)
            return u;
        for (int j = LOGN - 1; j >= 0; j--)
            if (Par[u][j] != Par[v][j])
            {

                u = Par[u][j];
                v = Par[v][j];
            }

        return Par[u][0];
    }

    int dist(int u, int v) {

        return h[u] + h[v] - 2 * h[lca(u, v)];
    }

    int jump(int u, int dist) {

        for (int i = LOGN - 1; i >= 0; i--)
            if (dist >= (1 << i))
            {

                u = Par[u][i];
                dist -= (1 << i);
            }

        return u;
    }

} LCA;