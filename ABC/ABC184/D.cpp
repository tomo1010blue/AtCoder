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

ld dp[105][105][105];

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    rep(i, 101) {
        rep(j, 101) {
            rep(k, 101) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[99][99][99] = 1;
    for(int i = 99; i >= 0; --i) {
        for(int j = 99; j >= 0; --j) {
            for(int k = 99; k >= 0; --k) {
                dp[i][j][k] = ((ld)(dp[i+1][j][k] + 1) * (ld) i + (ld)(dp[i][j+1][k] + 1) * (ld) j + (ld)(dp[i][j][k+1] + 1) * (ld) k) / (ld) (i + j + k);
            }
        }
    }
    cout << setprecision(9) << dp[a][b][c] << endl;
    return 0;
}