const int INF = 1e9 + 10;

struct line {

    int a, b;

    line() {

        a = 0;
        b = INF;

    }

    line(int _a, int _b) {

        a = _a;
        b = _b;

    }

    int operator() (int x) {

        return a * x + b;

    }

};

const int mxLine = 1e6;

line S[4 * mxLine + 10];

struct LiChaoTree {

    void addLine(int id, int l, int r, line New) {

        if (l == r) {

            if (S[id](l) > New(l))
                swap(S[id], New);
            
            return;

        }

        int mid = (l + r) / 2;

        if (S[id].a > New.a)
            swap(S[id], New);

        if (S[id](mid) > New(mid)) {

            swap(S[id], New);
            addLine(id * 2 + 1, mid + 1, r, New);

        } else 
            addLine(id * 2, l, mid, New);

    }

    int getQuery(int id, int l, int r, int x) {

        if (x < l || x > r)
            return INF;

        if (l == r)
            return S[id](x);

        int mid = (l + r) / 2;
        if (x <= mid)
            return min(S[id](x), getQuery(id * 2, l, mid, x));
        else
            return min(S[id](x), getQuery(id * 2 + 1, mid + 1, r, x));

    }

} LiChao;
