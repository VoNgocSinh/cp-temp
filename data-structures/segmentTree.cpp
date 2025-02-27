const int N = 2e5 + 100;
struct segmentTree {

    struct node {

        int ans;

        node () {

            ans = 0;
        }

        node (int a) {

            ans = a;
        }

        node operator+ (node a) {

            node res;
            
            //..
            
            return res;
        }

        void operator= (node a) {

            ans = a.ans;

        }

    } S[4 * N];

    void update(int id, int l, int r, int p, int k) {

        if (p < l || p > r)
            return;

        if (l == r) {

            S[id] = node(k);
            return;
        }

        int mid = (l + r) >> 1;

        update(id * 2, l, mid, p, k);
        update(id * 2 + 1, mid + 1, r, p, k);

        S[id] = S[id * 2] + S[id * 2 + 1];
    }

    node get(int id, int l, int r, int u, int v) {

        if (v < l || r < u)
            return node(0);
        
        if (l >= u && r <= v)
            return S[id];

        int mid = (l + r) / 2;

        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }

} IT;
