#include<bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) {return Point(x + p.x, y + p.y);}
    Point operator - (Point p) {return Point(x - p.x, y - p.y);}
    Point operator * (double a) {return Point(a * x, a * y);}
    Point operator / (double a) {return Point(x / a, y / a);}

    double abs() {return sqrt(norm());}
    double norm() {return x * x + y * y;}

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return equals(x, p.x) && equals(y, p.y);
    }
};

typedef Point Vector;

// 内積
double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

// 外積の大きさ
double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}
    
// 線分
struct Segment {
    Point p1, p2;
};
typedef Segment Line;

// 線分と線分の交点
Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

Segment input() {
    double x1, y1;
    double x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Segment s = {Point(x1, y1), Point(x2, y2)};

    return s;
}

int main() {
    int q;

    cin >> q;
    for (int i = 0; i < q; i++) {
        Segment s1 = input();
        Segment s2 = input();
        Point p = getCrossPoint(s1, s2);
        printf("%.10f %.10f\n", p.x, p.y);
    }
    
    return 0;
}
