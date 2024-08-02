const long double PI = 3.14159265358979;
struct point {
 
    double x, y;
 
    inline point() {x = y = 0;}
    inline point(double _x, double _y) {x = _x, y = _y;}
    bool operator < (point b) {return (x < b.x || (x == b.x && y < b.y));}
    bool operator > (point b) {return (x > b.x || (x == b.x && y > b.y));}
    bool operator == (point b) {return (x == b.x && y == b.y);}
    bool operator <= (point b) {return (x < b.x || (x == b.x && y <= b.y));}
    bool operator >= (point b) {return (x > b.x || (x == b.x && y >= b.y));}
};

inline double distance(point A, point B) {return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));}
inline double Rad_to_Deg(double rad) {return rad * 180 / PI;}
inline double Deg_to_Rad(double deg) {return deg / 180 * PI;}
point rotation(point p, double alpha) {

    double rad = Deg_to_Rad(alpha);
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

point rotations(point p1, point p2, double alpha) {

    double rad = Deg_to_Rad(alpha);
    point p3 = point(p1.x - p2.x, p1.y - p2.y);
    point p4 = point(p3.x * cos(rad) - p3.y * sin(rad), p3.x * sin(rad) + p3.y * cos(rad));

    return point(p4.x + p2.x, p4.y + p2.y);
}

long double cww(point A, point B, point C) {
 
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

struct line {
 
    double a, b, c;
    inline line () {a = b = c = 0;}
    inline line (double _a, double _b, double _c) {a = _a, b = _b, c = _c;}
};
 
 
line make_line(point a, point b) {
 
    line l = line(a.y - b.y, b.x - a.x, (a.x * b.y - a.y * b.x));
    return l;   
}
 
bool parallel(line l1, line l2) {
 
    double D = l1.a * l2.b - l2.a * l1.b;
    return (D == 0);

}
 
bool same(line l1, line l2) {
 
    double Dx = l1.c * l2.b - l2.c * l1.b;
    double Dy = l1.a * l2.c - l2.a * l1.c;

    return (parallel(l1, l2) && Dx == 0 && Dy == 0);
}
 
point intersect(line l1, line l2) {
 
    return point(-(l1.c * l2.b - l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b), -(l1.a * l2.c - l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b));
}