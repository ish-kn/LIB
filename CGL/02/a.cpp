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

bool isOrthogonal(Segment s1, Segment s2) {
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool isParallel(Segment s1, Segment s2) {
    return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

Segment input() {
    double x1, y1;
    double x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1 = Point(x1, y1);
    Point p2 = Point(x2, y2);
    Segment s = {p1, p2};

    return s;
}

int main() {
    int q;

    cin >> q;
    for (int i = 0; i < q; i++) {
        Segment s1 = input();
        Segment s2 = input();
        if (isParallel(s1, s2))
            cout << 2;
        else if (isOrthogonal(s1, s2))
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }

    return 0;
}
