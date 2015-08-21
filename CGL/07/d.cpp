#include<bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

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

class Circle {
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

// 射影
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}

// 円と直線の交点
pair<Point, Point> getCrossPoints(Circle c, Line l) {
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();
    double base = sqrt(c.r * c.r - (pr - c.c).norm());
    return make_pair(pr + e * base, pr - e * base);
}

Line input() {
    double x1, y1;
    double x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Line l = {Point(x1, y1), Point(x2, y2)};

    return l;
}

int main() {
    double cx, cy, r;
    int q;

    cin >> cx >> cy >> r;
    Circle c = Circle(Point(cx, cy), r);
    cin >> q;
    for (int i = 0; i < q; i++) {
        Line l = input();
        pair<Point, Point> p = getCrossPoints(c, l);
        Point p1 = p.first;
        Point p2 = p.second;
        if (p2 < p1) swap(p1, p2);
        printf("%.6f %.6f %.6f %.6f\n", p1.x, p1.y, p2.x, p2.y);
    }
    
    return 0;
}
