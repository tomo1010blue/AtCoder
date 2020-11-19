#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, r) repl(i, 0, r)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using mint = modint1000000007;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
template<class T> inline bool chmin(T &a, T b){
    if(a > b){a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a, T b){
    if(a < b){a = b; return true;}
    return false;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    ll a1 = 0;
    rep(i, n) a1 += (ll) abs(x[i]);
    cout << a1 << endl;
    ll sum = 0;
    rep(i, n) sum += (ll) x[i] * (ll) x[i];
    ld a2 = (ld) sqrt((ld) sum);
    cout << setprecision(15) << a2 << endl;
    int a3 = 0;
    rep(i, n) chmax(a3, abs(x[i]));
    cout << a3 << endl;
    return 0;
}