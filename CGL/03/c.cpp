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

// 多角形
typedef vector<Point> Polygon;

// 内積
double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

// 外積の大きさ
double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

// 点の内包
int contains(Polygon g, Point p) {
    int n = g.size();
    bool x = false;
    for (int i = 0; i < n; i++) {
        Point a = g[i] - p, b = g[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
        if (a.y > b.y) swap(a, b);
        if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
    }
    return x ? 2 : 0;
}

Point input() {
    double x, y;
    cin >> x >> y;
    return Point(x, y);
}

int main() {
    int n, q;
    Polygon g;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        Point p = input();
        g.push_back(p);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        Point p = input();
        cout << contains(g, p) << endl;
    }
    
    return 0;
}
