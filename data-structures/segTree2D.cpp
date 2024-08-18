struct segTree2D {

    int numChild = 1;

    struct node {

        // int gcdVal;
        int child[4];

    } S[N * 100];
    

    void build(int id, int xL, int yL, int xR, int yR) {
        if (xL > xR || yL > yR)
            return;

        if (xL == xR && yL == yR) {
            // S[id].gcdVal = a[xL][yL];
            return;
        }

        S[id].child[0] = ++numChild;
        S[id].child[1] = ++numChild;
        S[id].child[2] = ++numChild;
        S[id].child[3] = ++numChild;

        int midX = (xL + xR) >> 1;
        int midY = (yL + yR) >> 1;

        build(S[id].child[0], xL, yL, midX, midY);
        build(S[id].child[1], xL, midY + 1, midX, yR);
        build(S[id].child[2], midX + 1, yL, xR, midY);
        build(S[id].child[3], midX + 1, midY + 1, xR, yR);

        // S[id].gcdVal = __gcd(__gcd(S[S[id].child[0]].gcdVal, S[S[id].child[1]].gcdVal), __gcd(S[S[id].child[2]].gcdVal, S[S[id].child[3]].gcdVal));
    }

    void update(int id, int xL, int yL, int xR, int yR, int x, int y, int val) {
        if (xL > xR || yL > yR || x < xL || x > xR || y < yL || y > yR)
            return;

        if (xL == xR && yL == yR) {
            // S[id].gcdVal = val;
            return;
        }

        int midX = (xL + xR) >> 1;
        int midY = (yL + yR) >> 1;

        update(S[id].child[0], xL, yL, midX, midY, x, y, val);
        update(S[id].child[1], xL, midY + 1, midX, yR, x, y, val);
        update(S[id].child[2], midX + 1, yL, xR, midY, x, y, val);
        update(S[id].child[3], midX + 1, midY + 1, xR, yR, x, y, val);

        // S[id].gcdVal = __gcd(__gcd(S[S[id].child[0]].gcdVal, S[S[id].child[1]].gcdVal), __gcd(S[S[id].child[2]].gcdVal, S[S[id].child[3]].gcdVal));
    }

    int get(int id, int xL, int yL, int xR, int yR, int xQL, int yQL, int xQR, int yQR) {
        if (xL > xR || yL > yR || xR < xQL || xL > xQR || yR < yQL || yL > yQR)
            return 0;

        if (xL >= xQL && xR <= xQR && yL >= yQL && yR <= yQR)
            // return S[id].gcdVal;

        int midX = (xL + xR) >> 1;
        int midY = (yL + yR) >> 1;

        int g1 = get(S[id].child[0], xL, yL, midX, midY, xQL, yQL, xQR, yQR);
        int g2 = get(S[id].child[1], xL, midY + 1, midX, yR, xQL, yQL, xQR, yQR);
        int g3 = get(S[id].child[2], midX + 1, yL, xR, midY, xQL, yQL, xQR, yQR);
        int g4 = get(S[id].child[3], midX + 1, midY + 1, xR, yR, xQL, yQL, xQR, yQR);

        // return __gcd(__gcd(g1, g2), __gcd(g3, g4));
    }

} IT;
