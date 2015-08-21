#include<bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

// for CCW
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

// アンドリューのアルゴリズム
Polygon andrewScan(Polygon s) {
    Polygon u, l;
    if (s.size() < 3) return s;
    sort(s.begin(), s.end());
    // xが小さいものから２つuに追加
    u.push_back(s[0]);
    u.push_back(s[1]);
    // xが大きいものから２つlに追加
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);

    // 凸包の上部を生成
    for (int i = 2; i < s.size(); i++) {
        for (int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], s[i]) == COUNTER_CLOCKWISE; n--) {
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    // 凸包の下部を生成
    for (int i = s.size() - 3; i >= 0; i--) {
        for (int n = l.size(); n >= 2 && ccw(l[n-2], l[n-1], s[i]) == COUNTER_CLOCKWISE; n--) {
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    // 反時計周りになるように凸包の点の列を生成
    reverse(l.begin(), l.end());
    for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);

    return l;
}

Point input() {
    double x, y;
    cin >> x >> y;
    return Point(x, y);
}

int main() {
    int n;
    Polygon s;
    
    cin >> n;
    for (int i = 0; i < n; i++) s.push_back(input());

    Polygon ans = andrewScan(s), t = ans;
    int m = t.size();
    for (int i = 0; i < m; i++) swap(t[i].x, t[i].y);
    sort(t.begin(), t.end());
    for (int i = 0; i < m; i++) swap(t[i].x, t[i].y);
    Polygon::iterator it = find(ans.begin(), ans.end(), t[0]);
    int idx = it - ans.begin();
    
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        int x = ans[(idx+i) % m].x, y = ans[(idx+i) % m].y;
        printf("%d %d\n", x, y);
    }
        
    return 0;
}
