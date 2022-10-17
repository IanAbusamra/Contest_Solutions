#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using vi = vector<int>;
using pi = pair<int,int>;
using vpi = vector<pi>;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

//ordered set data structure: operations - insert(), order_of_key(k) (numberof elements strictly smaller than k),
//find_by_order() (returns iterator to ith largest element)
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define watch(x) cout << (#x) << " = " << (x) << endl
#define sz (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))

#define sec second
#define fir first

#define MAX_INT 1e18*9

#define For(i,a,b) for (int i = (a); i < (b); ++i)
#define Forll(i,a,b) for (ll i = (a); i < (b); ++i)
bool ckmin(int& a, int b){ return b < a ? a = b, true : false; }
bool ckmax(int& a, int b){ return b > a ? a = b, true : false; }
bool ckminll(ll& a, ll b){ return b < a ? a = b, true : false; }
bool ckmaxll(ll& a, ll b){ return b > a ? a = b, true : false; }

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

/*
---------1---------2---------3---------4---------5---------6---------7---------
1234567890123456789012345678901234567890123456789012345678901234567890123456789
*/
void solve() {
	int n; cin >> n;
	map<int, int> mp;
	vi a(n); 
	For(i, 0, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int cnt1 = 0, cnt2 = 0;
	for(auto [x, y] : mp) {
		if(y == 1) cnt1++;
		else cnt2++;
	}

	cout << cnt2 + ((cnt1+1)/2) << endl;

}

int main() {
 int t; cin >> t;
 while(t--) {
	 solve();
 }
}
