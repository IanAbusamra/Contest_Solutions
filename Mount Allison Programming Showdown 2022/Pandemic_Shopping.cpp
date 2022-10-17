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

void solve() {
    map<string, int> dx;
    //map directions to integers
    dx["S2N"] = 0;
    dx["W2E"] = 1;
    dx["N2S"] = 2;
    dx["E2W"] = 3;

    ll n, k; cin >> n >> k;

    //-1 means the arrow is not predefined
    ll A = -1, B = -1;
    vector<int> paisles(n, -1);

    //input
    for(int i = 0; i < k; i++) {
        string aisle; cin >> aisle;
        string dir; cin >> dir;
        if(aisle == "A") A = dx[dir];
        else if(aisle == "B") B = dx[dir];
        else paisles[stoi(aisle) - 1] = dx[dir];
    }

    ll finalans = 0;

    //both vertical aisles facing up
    if((A == 0 || A == -1) && (B == 0 || B == -1)) {
        //only arrangement is alternating
        bool can = true;
        if(n % 2 == 0) can = false;
        for(int i = 0; i < n; i++) {
            if(paisles[i] == -1) continue;
            if(i % 2 == 0 && paisles[i] == 3) can = false;
            if(i % 2 == 1 && paisles[i] == 1) can = false;
        }
        finalans += (can ? 1LL : 0LL);
    }

    //both vertical aisles facing down
    if((A == 2 || A == -1) && (B == 2 || B == -1)) {
        //only arrangement is alternating
        bool can = true;
        if(n % 2 == 0) can = false;
        for(int i = 0; i < n; i++) {
            if(paisles[i] == -1) continue;
            if(i % 2 == 0 && paisles[i] == 1) can = false;
            if(i % 2 == 1 && paisles[i] == 3) can = false;
        }
        finalans += (can ? 1LL : 0LL);
    }

    //left vertical facing up, right vertical facing down
    if((A == 0 || A == -1) && (B == 2 || B == -1)) {
        if((paisles[0] != 3 && paisles[0] != -1) || (paisles[n-1] != 1 && paisles[n-1] != -1)) {
            goto fail1;
        }
        ll ans = 1;
        for(int i = 1; i < n-1; i++) {
            if(paisles[i] == -1) ans *= 2;
        }
        finalans += ans;
    }

    fail1:
    //right vertical facing up, left vertical facing down
    if((A == 2 || A == -1) && (B == 0 || B == -1)) {
        if((paisles[0] != 1 && paisles[0] != -1) || (paisles[n-1] != 3 && paisles[n-1] != -1)) {
            goto fail2;
        }
        
        ll ans = 1;
        for(int i = 1; i < n-1; i++) {
            if(paisles[i] == -1) ans *= 2;
        }
        finalans += ans;
    }

    fail2:
    cout << finalans << endl;
}

int main() {
    setIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}
