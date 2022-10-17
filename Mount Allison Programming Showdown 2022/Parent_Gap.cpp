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

int nextyear(int year, int dow) {
    //we are on a certain year, and the first day of the year is 'dow'
    int days = 365;
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) days++;
    int closest = (days/7)*7;
    while(closest != days) {
        closest++;
        dow++;
    }
    dow %= 7;
    return dow;
}

void solve() {
    int year; cin >> year;

    int january = 31;
    int february;
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) february = 29;
    else february = 28;
    int march = 31;
    int april = 30;
    int may = 31;

    int dow = 5; //Jan. 1st, 2000 was a Saturday
    int cur_year = 2000;
    while(cur_year != year) {
        dow = nextyear(cur_year, dow);
        cur_year++;
    }

    //Mother's day
    int may1_tot = january + february + march + april + 1;
    int days = 1;
    while(days < may1_tot || dow != 6) {
        days++;
        dow++;
        dow %= 7;
    }
    days += 7;
    int mother = days;

    //Father's day
    int june1_tot = may1_tot + may;
    while(days < june1_tot || dow != 6) {
        days++;
        dow++;
        dow %= 7;
    }
    days += 7;
    days += 7;

    cout << ((days - mother)/7);
    cout << " weeks" << endl;
}

int main() {
    setIO();
    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}
