struct segtreeLazy {
 
    struct node {
 
        int ans, lazy;
 
        node () { ans = lazy = 0;}
        node (int a, int b) { ans = a, lazy = b;}
 
        node operator+ (node a) {
 
            node res;
            // res.ans = ..;
            return res;
        }
 
        void operator= (node a) {
 
            ans = a.ans;
            lazy = a.lazy;
        }
 
    } S[4 * N];
 
    void pushDown(int id, int l, int r) {
 
        if (l == r)
            return;
        
        if (S[id].lazy) {

            //..

            S[id].lazy = 0;
        }

    }
 
    void update(int id, int l, int r, int u, int v, int x) {
 
        if (r < u || l > v)
            return;
        
        pushDown(id, l, r);
 
        if (l >= u && r <= v) {
 
            //..
 
            return;
        }
 
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, x);
        update(id * 2 + 1, mid + 1, r, u, v, x);
 
        S[id] = S[id * 2] + S[id * 2 + 1];
 
    }
 
    node get(int id, int l, int r, int u, int v) {
 
        if (r < u || l > v)
            return node(0, 0);
 
        pushDown(id, l, r);
        
        if (l >= u && r <= v)
            return S[id];
        
        int mid = (l + r) >> 1;
 
        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
 
    }
 
} IT;