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

vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for(ll a = 2; a * a <= n; ++a) {
        if(n % a != 0) continue;
        ll ex = 0;
        while(n % a == 0) {
            ++ex;
            n /= a;
        }
        res.pb({a, ex});
    }
    if(n != 1) res.pb({n, 1});
    return res;
}

int main(void) {
    int n;
    cin >> n;
    int ans = 0;
    repl(c, 1, n) {
        int k = n - c;
        const auto &pf = prime_factorize(k);
        ll res = 1;
        for(auto p : pf) res *= p.se + 1;
        ans += res;
    }
    cout << ans << endl;
    return 0;
}