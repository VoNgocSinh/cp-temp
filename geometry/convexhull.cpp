struct point {

    long double x, y;

} p[N];

long double ccw(point A, point B, point C) {

    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

void komasan() {
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;

    sort(p + 1, p + n + 1, [&](point A, point B) {
        if (A.x != B.x)
            return A.x < B.x;

        return A.y < B.y;
    });

    vector<point> hullA, hullB;

    for (int i = 1; i <= n; i++) {
        if (hullA.empty()) {
            hullA.push_back(p[i]);
            continue;
        }

        while (hullA.size() > 1 && ccw(hullA[hullA.size() - 2], hullA[hullA.size() - 1], p[i]) >= 0)
            hullA.pop_back();

        hullA.push_back(p[i]);
    }

    for (int i = n; i >= 1; i--) {
        if (hullB.empty()) {
            hullB.push_back(p[i]);
            continue;
        }

        while (hullB.size() > 1 && ccw(hullB[hullB.size() - 2], hullB[hullB.size() - 1], p[i]) >= 0)
            hullB.pop_back();

        hullB.push_back(p[i]);
    }

    for (int i = 1; i < hullB.size() - 1; i++) hullA.push_back(hullB[i]);

    cout << hullA.size();

}

