const int N = 2e5 + 10;

struct DisjointSetUnion {

    int Par[N];
    vector<int> a[N];

    void prepare(int n) {

        for (int i = 1; i <= n; i++) {

            a[i].clear();
            a[i].push_back(i);
            Par[i] = i;
        }
    }

    bool join(int u, int v) {

        if (Par[u] == Par[v])
            return false;
        u = Par[u];
        v = Par[v];

        if (a[u].size() < a[v].size())
            swap(u, v);
        for (int x : a[v]) {

            a[u].push_back(x);
            Par[x] = u;
        }

        return true;
    }

} DSU;