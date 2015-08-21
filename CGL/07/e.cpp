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

double arg(Vector p) {return atan2(p.y, p.x);}

// r回転
Vector polar(double a, double r) {return Point(cos(r) * a, sin(r) * a);}

// 円と円の交点
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
    double d = (c1.c - c2.c).abs();
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

Circle input() {
    double cx, cy, r;
    cin >> cx >> cy >> r;
    return Circle(Point(cx, cy), r);
}

int main() {
    Circle c1 = input(), c2 = input();
    pair<Point, Point> p = getCrossPoints(c1, c2);
    Point p1 = p.first, p2 = p.second;
    if (p2 < p1) swap(p1, p2);
    printf("%.7f %.7f %.7f %.7f\n", p1.x, p1.y, p2.x, p2.y);
    
    return 0;
}
