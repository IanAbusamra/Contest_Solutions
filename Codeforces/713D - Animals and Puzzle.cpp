#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
#define watch(x) cout << (#x) << " = " << (x) << endl

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

const int mxN = 1005;
const int mxM = 1005;
const int LOG = 10;
int st[LOG][mxN][LOG][mxM];

void solve() {

    int n, m; cin >> n >> m;

    //complete dp where dp[i][j] = maximal square of 1s ending at i, j
    for(int ir = 0; ir < n; ir++) {
        for(int ic = 0; ic < m; ic++) {
            int cn; cin >> cn;
            if(cn == 1) {
                st[0][ir][0][ic] = 1;
                if(ir > 0 && ic > 0) {
                    st[0][ir][0][ic] += min({st[0][ir-1][0][ic], st[0][ir][0][ic-1], st[0][ir-1][0][ic-1]});
                }
            }
        }
    }

    for(int ir = 0; ir < n; ir++) {
        for(int jc = 1; jc <= __lg(m+1); jc++) {
            for(int ic = 0; ic + (1<<jc) <= m; ic++) {
                st[0][ir][jc][ic] = max(st[0][ir][jc-1][ic], st[0][ir][jc-1][ic+(1<<(jc-1))]);
            }
        }
    }

    for(int jr = 1; jr <= __lg(n+1); jr++) {
        for(int ir = 0; ir + (1<<jr) <= n; ir++) {
            for(int jc = 0; jc <= __lg(m+1); jc++) {
                for(int ic = 0; ic + (1<<jc) <= m; ic++) {
                    st[jr][ir][jc][ic] = max(st[jr-1][ir][jc][ic], st[jr-1][ir+(1<<(jr-1))][jc][ic]);
                }
            }
        }
    }

    auto rmq = [&] (int x1, int y1, int x2, int y2) {
        int kx = __lg(x2 - x1 + 1);
        int ky = __lg(y2 - y1 + 1);
        int op1 = max(st[kx][x1][ky][y1], st[kx][x1][ky][y2 - (1<<ky) + 1]);
        int op2 = max(st[kx][x2 - (1<<kx) + 1][ky][y1], st[kx][x2 - (1<<kx) + 1][ky][y2 - (1<<ky) + 1]);
        return max(op1, op2);
    };

    int q; cin >> q;
    while(q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        //binary search on the maximal size square 'x'.
        int mn = min(x2 - x1 + 1, y2 - y1 + 1);
        int lo = 0, hi = mn;
        if(x1 == x2 || y1 == y2) {
            cout << min(mn, rmq(x1, y1, x2, y2)) << endl;
            continue;
        }
        while(lo < hi) {
            int mid = (lo + hi + 1)/2;
            int cur = (mid == 0 ? 0 : rmq(x1 + mid - 1, y1 + mid - 1, x2, y2));
            if(cur >= mid) {
                lo = mid;
            }
            else hi = mid - 1;
        }
        cout << lo << endl;
    }
}   

int main() {
    setIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}
