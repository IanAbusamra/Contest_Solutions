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
    int n, p; cin >> n >> p;
    map<string, char> mp;
    map<string, char> options;

    options["number of"] = 'c';
    options["amount of"] = 'm';
    options["most"] = 'x';
    options["fewest"] = 'c';
    options["least"] = 'm';
    options["more"] = 'x';
    options["fewer"] = 'c';
    options["less"] = 'm';
    options["many"] = 'c';
    options["much"] = 'm';
    options["few"] = 'c';
    options["little"] = 'm';


    for(int i = 0; i < n; i++) {
        string word; cin >> word;
        char type; cin >> type;
        mp[word] = type;
    }

    for(int i = 0; i < p; i++) {
        string p1, p2, p3;
        cin >> p1 >> p2;
        if(p2 == "of") {
            cin >> p3;
            p1 = p1 + " of";
            p2 = p3;
        }
        char needed_type = options[p1];
        char our_type = mp[p2];

        if(needed_type == 'x') {
            cout << "Correct!" << endl;
        }
        else {
            cout << (needed_type == our_type ? "Correct!" : "Not on my watch!") << endl;
        }
        
    }
}

int main() {
    setIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}
