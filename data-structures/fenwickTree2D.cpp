struct fenwickTree2D {

    vector<vector<int>> BIT;
    int n, m;

    fenwickTree2D(int _n, int _m) {

        n = _n;
        m = _m;

        BIT = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    
    }

    void update(int _x, int _y, int val) {

        for (int x = _x; x <= n; x += (x & (-x)))
            for (int y = _y; y <= m; y += (y & (-y)))
                BIT[x][y] += val;

    }

    int get(int _x, int _y) {

        int sum = 0;
        for (int x = _x; x; x -= (x & (-x)))
            for (int y = _y; y; y -= (y & (-y)))
                sum += BIT[x][y];

        return sum;

    }

    int get(int x, int y, int u, int v) {

        return get(u, v) - get(x - 1, v) - get(u, y - 1) + get(x - 1, y - 1);

    }

};