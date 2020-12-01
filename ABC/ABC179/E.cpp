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
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> id(m, -1);
    vector<int> a;
    int len = 0;
    ll tot = 0;
    while(id[x] == -1) {
        a.pb(x);
        id[x] = len;
        tot += x;
        x = (x * x) % m;
        ++len;
    }
    int c = len - id[x];
    ll s = 0;
    repl(i, id[x], len) s += a[i];
    ll ans = 0;
    if(n <= len) {
        rep(i, n) {
            ans += a[i];
        }
    } else {
        ans += tot;
        n -= len;
        ans += s * (n / c);
        n %= c;
        rep(i, n) ans += a[id[x] + i];
    }
    cout << ans << endl;
    return 0;
}