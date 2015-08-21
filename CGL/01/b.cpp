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

// 外積
double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}
    
// 線分
struct Segment {
    Point p1, p2;
};
typedef Segment Line;

// 射影
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}

// 反射
Point reflect(Segment s, Point p) {
    return p + (project(s, p) - p) * 2.0;
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
    
    Segment s = input();
    cin >> q;
    for (int i = 0; i < q; i++) {
        double x, y;
        cin >> x >> y;
        Point p = reflect(s, Point(x, y));
        printf("%.10f %.10f\n", p.x, p.y);
    }

    return 0;
}
