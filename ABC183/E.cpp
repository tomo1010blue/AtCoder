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
using G = vector<vector<mint>>;
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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    G dp(h, vector<mint>(w));
    G x(h, vector<mint>(w));
    G y(h, vector<mint>(w));
    G z(h, vector<mint>(w));
    dp[0][0] = 1;
    rep(i, h) {
        rep(j, w) {
            if(i == 0 && j == 0) continue;
            if(s[i][j] == '#') continue;
            if(i > 0) x[i][j] = x[i-1][j] + dp[i-1][j];
            if(j > 0) y[i][j] = y[i][j-1] + dp[i][j-1];
            if(i > 0 && j > 0) z[i][j] = z[i-1][j-1] + dp[i-1][j-1];
            dp[i][j] = x[i][j] + y[i][j] + z[i][j];
        }
    }
    cout << dp[h-1][w-1].val() << endl;
    return 0;
}