#include<bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

// 端点の種類
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

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

class Circle {
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

class EndPoint {
public:
    Point p;
    int seg, st; // 入力線分のID, 端点の種類
    
    EndPoint() {};
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

    bool operator < (const EndPoint &ep) const {
        // y座標が小さい順に整列
        if (p.y == ep.p.y) {
            // yが同一なら、下端点、左端点、右端点、上端点の順に並べる
            return st < ep.st; 
        } else return p.y < ep.p.y;
    }
};

EndPoint EP[2 * 100000]; // 端点のリスト

// 線分
struct Segment {
    Point p1, p2;
};
typedef Segment Line;

// 線分交差問題：マンハッタン幾何
int manhattanIntersection(vector<Segment> S) {
    int n = S.size();

    for (int i = 0, k = 0; i < n; i++) {
        // 端点p1, p2が左下を基準に並ぶように調整
        if (S[i].p1.y == S[i].p2.y) {
            if (S[i].p1.x > S[i].p2.x) swap(S[i].p1, S[i].p2);
        } else if (S[i].p1.y > S[i].p2.y) swap(S[i].p1, S[i].p2);

        if (S[i].p1.y == S[i].p2.y) { // 水平線分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, LEFT);
            EP[k++] = EndPoint(S[i].p2, i, RIGHT);
        } else { // 垂直成分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(S[i].p2, i, TOP);
        }
    }

    sort(EP, EP + (2 * n)); // 端点のy座標に関して昇順に整列

    set<int> BT;
    BT.insert(1000000001); // 番兵を設置
    int cnt = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (EP[i].st == TOP) {
            BT.erase(EP[i].p.x); // 上端点を削除
        } else if (EP[i].st == BOTTOM) {
            BT.insert(EP[i].p.x); // 下端点を追加
        } else if (EP[i].st == LEFT) {
            set<int>::iterator b = lower_bound(BT.begin(), BT.end(), S[EP[i].seg].p1.x);
            set<int>::iterator e = upper_bound(BT.begin(), BT.end(), S[EP[i].seg].p2.x);
            cnt += distance(b, e); // bとeの距離（点の数）を加算
        }
    }

    return cnt;
}

Segment input() {
    double x1, y1;
    double x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Segment s = {Point(x1, y1), Point(x2, y2)};

    return s;
}

int main() {
    int n;
    vector<Segment> S;

    cin >> n;
    for (int i = 0; i < n; i++) S.push_back(input());
    cout << manhattanIntersection(S) << endl;
    
    return 0;
}
