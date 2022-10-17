#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
#define watch(x) cout << (#x) << " = " << (x) << endl
#define sz (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define sec second
#define fir first
#define For(i,a,b) for (int i = (a); i < (b); ++i)

template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}
template<class T> bool ckmin(T& a, const T& b) {
    return a > b ? a = b, 1 : 0;
}

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

/*
---------1---------2---------3---------4---------5---------6---------7---------
1234567890123456789012345678901234567890123456789012345678901234567890123456789
*/

long double PI = 3.141592653589;
//Geometry
//point
struct Point {
    ld x, y; 
    void read() {
        cin >> x >> y;
    }
    Point operator - (const Point& B) const{
        return Point{x - B.x, y - B.y};
    }
    void operator -= (const Point& B) {
        x -= B.x;
        y -= B.y;
    }
    ld operator * (const Point& B) const{
    return x * B.y - y * B.x;
    }
    ld cross(const Point& B, const Point& C) const {
        return (B - *this) * (C - *this);
    }
  bool operator < (const Point& B) const {
    return make_pair(x, y) < make_pair(B.x, B.y);
  }
  bool operator > (const Point& B) const {
    return make_pair(x, y) > make_pair(B.x, B.y);
  }
};
 
//returns TWICE area
ld area(vector<Point> polygon) {
    ld area = 0;
    int n = (int) polygon.size();
    for(int i = 0; i < n; i++) {
        area += polygon[i] * polygon[i+1 == n ? 0 : i+1];
    }
    area = abs(area);
    return area;
}

vector<Point> convex_hull(vector<Point> polygon) {
    vector<Point> hull;
    for(int rep = 0; rep < 2; ++rep) {
        const int S = hull.size();
        for(Point C : polygon) {
        while((int) hull.size() - S >= 2) {
            Point A = hull.end()[-2];
            Point B = hull.end()[-1];
            if(A.cross(B, C) <= 0) {
                break;
            }
            hull.pop_back();
        }
        hull.push_back(C);
        }
        hull.pop_back();
        reverse(polygon.begin(), polygon.end());
    }
    return hull;
}

void solve() {
    ll n, d, g; cin >> n >> d >> g;
    vector<Point> shape(n);
    for(int i = 0; i < n; i++) {
        cin >> shape[i].x >> shape[i].y;
    }
    sort(shape.begin(), shape.end());
    shape = convex_hull(shape);
    
    long double ans = area(shape)/(long double) 2;
    long double circle = (long double)g * (long double)g * (long double)d * (long double)d * M_PI;

    for(int i = 0; i < n; i++) {
        long double toadd = sqrtl((shape[i].x - shape[(i+1) % n].x) * (shape[i].x - shape[(i+1) % n].x) +
        (shape[i].y - shape[(i+1) % n].y) * (shape[i].y - shape[(i+1) % n].y));
        toadd *= d*g;
        ans += toadd;
        //cout << toadd << endl;
    }

    ans += circle;
    cout << std::setprecision(12) << ans << endl;
}

int main() {
    setIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}
