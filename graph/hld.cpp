struct HeavyLightDecomposion {

    int cntNode = 0;
    int numPath = 1;

    int idPath[N], indST[N], Par[N], nodeHP[N], h[N];

    HeavyLightDecomposion() {

        nodeHP[1] = 1;
    }

    void build(int u, int par) {

        idPath[u] = numPath;
        indST[u] = ++cntNode;
        Par[u] = par;
        h[u] = h[par] + 1;

        bool check = true;
        for (int x : edge[u])
            if (x != par) {

                if (!check) {

                    numPath++;
                    nodeHP[x] = x;
                } else {

                    check = false;
                    nodeHP[x] = nodeHP[u];
                }
                
                build(x, u);
            }
    }

    int getPath(int u, int v) {

        int res = 0;

        while (nodeHP[u] != nodeHP[v]) {

            if (h[Par[nodeHP[u]]] < h[Par[nodeHP[v]]])
                swap(u, v);

            //get:indST[nodeHP[u]] -> indST[u]

            u = Par[nodeHP[u]];
        }

        if (indST[u] > indST[v])
            swap(u, v);

        //get:indST[u] -> indST[v]

        return res;
    }

    void updatePath(int u, int v, int value) {

        int res = -1;

        while (nodeHP[u] != nodeHP[v]) {

            if (h[Par[nodeHP[u]]] < h[Par[nodeHP[v]]])
                swap(u, v);

            //update:indST[nodeHP[u]] -> indST[u]

            u = Par[nodeHP[u]];
        }

        if (indST[u] > indST[v])
            swap(u, v);

        //update:indST[u] -> indST[v]
    }
} hld;
