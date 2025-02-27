const int N = 1e6 + 10;
const int LOG = 20;
struct sparseTable {

    int r[N][LOG];

    void prepare(int n, int a[]) {

        for (int i = 1; i <= n; i++)
            r[i][0] = a[i];

        for (int j = 1; j < LOG; j++)
            for (int i = 1; i <= n - (1 << j) + 1; i++)
                r[i][j] = min(r[i][j - 1], r[i + (1 << (j - 1))][j - 1]);

    }

    int get(int L, int R) {

        int lb = (R - L == 0 ? 0 : log2(R - L));
        return min(r[L][lb], r[R - (1 << lb) + 1][lb]);

    }

}