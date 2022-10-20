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
const int mxN = 100009;
int stmn[20][mxN];
int stmx[20][mxN];

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> stmn[0][i];
        stmx[0][i] = stmn[0][i];
    }

    for(int j = 1; j <= __lg(n+1); j++) {
        for(int i = 0; i + (1<<j) <= n; i++) {
            stmn[j][i] = min(stmn[j-1][i], stmn[j-1][i + (1<<(j-1))]);
            stmx[j][i] = max(stmx[j-1][i], stmx[j-1][i + (1<<(j-1))]);
        }
    }

    auto rmqmn = [&] (int l, int r) {
        int k = __lg(r - l + 1);
        return min(stmn[k][l], stmn[k][r - (1<<k) + 1]);
    };

    auto rmqmx = [&] (int l, int r) {
        int k = __lg(r - l + 1);
        return max(stmx[k][l], stmx[k][r - (1<<k) + 1]);
    };

    int q; cin >> q;

    while(q--) {
        int l, r; cin >> l >> r;
        long double left = (l == 0 ? 0.0L : (long double) rmqmx(0, l-1));
        long double right = (r == n-1 ? 0.0L : (long double) rmqmx(r + 1, n-1));
        int z = rmqmn(0, 1);
        long double middle = (long double) rmqmn(l, r);
        long double mxmiddle = (long double) rmqmx(l, r);
        long double ans = middle + max({left, right, (mxmiddle - middle) / 2.0L});
        //watch(left);
        //watch(middle);
        //watch(right);
        cout << fixed << setprecision(1) << ans << endl;
    }
}   

int main() {
    setIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}
