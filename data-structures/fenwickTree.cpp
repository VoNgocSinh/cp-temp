struct fenwickTree {

    vector<int> BIT;
    int n;

    fenwickTree(int _n) {

        n = _n;
        BIT.resize(n + 1);
    }

    void update(int u, int val) {

        int idx = u;
        while (idx <= n) {
        
            BIT[idx] += val;
            idx += (idx & (-idx));
        }
    }

    int get(int p) {

        int idx = p, ans = 0;
        while (idx > 0) {
    
            ans += BIT[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }

    int get(int l, int r) {

        return get(r) - get(l - 1);
    }
};