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


// 反時計回りCCW
int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() < b.norm()) return ONLINE_FRONT;

    return ON_SEGMENT;
}

Point input() {
    double x1, y1;
    cin >> x1 >> y1;
    return Point(x1, y1);
}

int main() {
    int q;

    Point p0 = input();
    Point p1 = input();
    cin >> q;
    for (int i = 0; i < q; i++) {
        Point p2 = input();
        int res = ccw(p0, p1, p2);
        switch (res) {
        case COUNTER_CLOCKWISE:
            cout << "COUNTER_CLOCKWISE";
            break;
        case CLOCKWISE:
            cout << "CLOCKWISE";
            break;
        case ONLINE_BACK:
            cout << "ONLINE_BACK";
            break;
        case ONLINE_FRONT:
            cout << "ONLINE_FRONT";
            break;
        default:
            cout << "ON_SEGMENT";
            break;
        }
        cout << endl;
    }
    
    return 0;
}
