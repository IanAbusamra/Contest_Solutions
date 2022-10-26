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

const int mxN = 1e5+5;
const int LOG = 17;
array<int, 2> st[LOG][mxN];

void solve() {
    int n; cin >> n;    
    st[0][n-1][0] = n-1;
    st[0][n-1][1] = n-1;
    for(int i = 0; i < n-1; i++) {
        cin >> st[0][i][0];
        st[0][i][0]--;
        st[0][i][1] = i;
    }

    for(int j = 1; j <= __lg(n+1); j++) {
        for(int i = 0; i + (1<<j) <= n; i++) {
            if(st[j-1][i][0] > st[j-1][i+(1<<(j-1))][0]) {
                st[j][i][0] = st[j-1][i][0];
                st[j][i][1] = st[j-1][i][1];
            }
            else {
                st[j][i][0] = st[j-1][i+(1<<(j-1))][0];
                st[j][i][1] = st[j-1][i+(1<<(j-1))][1];
            }
        }
    }

    auto rmq = [&] (int l, int r) {
        int k = __lg(r - l + 1);
        if(st[k][l][0] > st[k][r - (1<<k) + 1][0]) {
            return st[k][l][1];
        }
        else {
            return st[k][r - (1<<k) + 1][1];
        }
    };
    
    vector<long long> dp(n);
    long long ans = 0;
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        long long fstr = rmq(i + 1, st[0][i][0]);
        dp[i] = (dp[fstr] - (st[0][i][0] - fstr)) + (n - i - 1);
        ans += dp[i];
    }

    cout << ans << endl;
}   

int main() {
    setIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}
