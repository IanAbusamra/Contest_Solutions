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

const int mxN = 100005;
int st[6][20][mxN];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int detail = 0; detail < m; detail++) {
            cin >> st[detail][0][i];
        }
    }

    for(int j = 1; j <= __lg(n+1); j++) {
        for(int i = 0; i + (1<<j) <= n; i++) {
            for(int detail = 0; detail < m; detail++) {
                st[detail][j][i] = max(st[detail][j-1][i], st[detail][j-1][i + (1<<(j-1))]);
            }
        }
    }

    auto rmq = [&] (int detail, int l, int r) {
        int kk = __lg(r - l + 1);
        return max(st[detail][kk][l], st[detail][kk][r - (1<<kk) + 1]);
    };

    //binary search on the longest segment s.t. you kill all contained robots
    int lo = 0, hi = n;
    vector<int> ans(m);

    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        int need = 1e9;
        vector<int> temp(m);
        vector<int> ntemp(m);
        for(int i = 0; i + mid - 1 < n; i++) {
            int cur = 0;
            for(int z = 0; z < m; z++) {
                int tokill = (mid == 0 ? 0 : rmq(z, i, i + mid - 1));
                cur += tokill;
                temp[z] = tokill;
            }
            if(cur < need) {
                need = cur;
                ntemp = temp;
            }
        }   
        
        if(need > k) {
            hi = mid - 1;
        }
        else {
            lo = mid;
            ans = ntemp;
        }
    }

    for(auto &shots : ans) {
        cout << shots << " ";
    }
    cout << endl;
}   

int main() {
    setIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}
