long double ccw(point A, point B, point C) {

    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}
 
string pointInPolygon(point m, vector<point> & p) {

    if (ccw(p[0], p[1], p[2]) < 0)
        reverse(p.begin(), p.end());

    int sz = p.size();
    int cnt = 0;

    for (int i = 0; i < sz; i++) {

        if (p[i].x <= m.x && m.x < p[(i + 1) % sz].x && ccw(p[i], p[(i + 1) % sz], m) < 0) 
            cnt++;
        else 
            if (p[(i + 1) % sz].x <= m.x && m.x < p[i].x && ccw(p[(i + 1) % sz], p[i], m) < 0)  
                cnt++;

        long long s = ccw(p[i], p[(i + 1) % sz], m);

        if (s == 0) {

            if (m.x >= min(p[i].x, p[(i + 1) % sz].x) && m.x <= max(p[i].x, p[(i + 1) % sz].x))
                if (m.y >= min(p[i].y, p[(i + 1) % sz].y) && m.y <= max(p[i].y, p[(i + 1) % sz].y))
                    return "BOUNDARY";

        }

    }

    return (cnt % 2 ? "INSIDE" : "OUTSIDE");

}