#include <bits/stdc++.h>
using namespace std;

//shortcuts
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
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
bool ckmin(int& a, int b){ return b < a ? a = b, true : false; }
bool ckmax(int& a, int b){ return b > a ? a = b, true : false; }
bool ckminll(ll& a, ll b){ return b < a ? a = b, true : false; }
bool ckmaxll(ll& a, ll b){ return b > a ? a = b, true : false; }

//ordered set data structure: operations - insert(), order_of_key(k) (numberof elements strictly smaller than k),
//find_by_order() (returns iterator to ith largest element)
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

// For every i, finds the smallest j > i such that `compare(values[j], values[i])` is true, or `n` if no such j exists.
//https://codeforces.com/contest/1696/standings, neal prob D
template<typename T, typename T_compare>
vector<int> closest_right(const vector<T> &values, T_compare &&compare) {
    int n = int(values.size());
    vector<int> closest(n);
    vector<int> stack;
 
    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && !compare(values[stack.back()], values[i]))
            stack.pop_back();
 
        closest[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }
 
    return closest;
}

ll nCk(ll n, ll k)
{
    //sometimes you instead need: if k > n return 0. Check this
    ll res = 1;
    if (k > n - k) k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll modpow(ll x, ll y, ll p) {
	ll res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x; x %= p;
		y >>= 1;
	}
	return res;
}

vector<ll> genPrimes(ll n) {
	vector<ll> primes;
    while (n % 2 == 0) {	
		primes.pb(2);
        n = n/2;
    }
    for (ll i = 3; i*i <= n; i = i + 2) {
        while (n % i == 0) {
			primes.pb(i);
            n = n/i;
        }
    }
    if (n > 2) primes.pb(n);
	return primes;
}

vector<ll> genPrimesD(ll n) {
	vector<ll> primes;
	bool have = false;
    while (n % 2 == 0) {	
		if(!have) {primes.pb(2); have = true;}
        n = n/2;
    }
    for (ll i = 3; i*i <= n; i = i + 2) {
		have = false;
        while (n % i == 0) {
			if(!have) {primes.pb(i); have = true;}
            n = n/i;
        }
    }
    if (n > 2) primes.pb(n);
	return primes;
}

struct Fenwick{
    // 0 based indexing
    vector<ll> v;
    int _n;
    Fenwick(int n) {
        v.assign(n+5,0);
        _n = n+5;
    }
    void upd(int pos, ll val) {
        while(pos<_n) {
            v[pos]+=val;
            v[pos];
            pos|=(pos+1);
        }
    }
    ll qr(int pos) {
        ll ret = 0;
        while(pos>=0) {
            ret += v[pos];
            pos&=(pos+1);
            pos--;
        }
        return ret;
    }
};

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

//we can arrange the 1s in any way we want as long as there is at least
//one zero between all of them and at least as many 1 "segments"
void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    //first verify endpoints
    if(a[0] != b[0] || a[n-1] != b[n-1]) {
        cout << -1 << endl;
        return;
    }

    //create a vector of pairs for l and r of each segment of 1s
    vpi alr, blr;

    //get a's segments 
    For(i, 0, n-1) {
        if(a[i] == '1') {
            int l = i;
            while(i < n-1 && a[i+1] == '1') {
                i++;
            }
            int r = i;
            alr.pb({l, r});
        }
    }
    //have to check last index
    if(alr.size()) {
        if(alr.back().sec != n-1 && a[n-1] == '1') alr.pb({n-1, n-1});
    }
    else {
        if(a[n-1] == '1') alr.pb({n-1, n-1});
    }

    //get b's segments
    For(i, 0, n-1) {
        if(b[i] == '1') {
            int l = i;
            while(i < n-1 && b[i+1] == '1') {
                i++;
            }
            int r = i;
            blr.pb({l, r});
        }
    }
    //have to check last 1
    if(blr.size()) {
        if(blr.back().sec != n-1 && b[n-1] == '1') blr.pb({n-1, n-1});
    }
    else {
        if(b[n-1] == '1') blr.pb({n-1, n-1});
    }

    if(alr.size() != blr.size()) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    
    //calculate minimum time
    For(i, 0, alr.size()) {
        ans += abs(alr[i].fir - blr[i].fir) + abs(alr[i].sec - blr[i].sec);
    }

    cout << ans << endl;
}   


int main() {
    setIO();
    int t; cin >> t;
    while(t--) {
	solve();
    }
}


