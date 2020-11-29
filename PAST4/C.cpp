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
#define sz(x) ((int) (x).size())
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using mint = modint1000000007;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1, 0};
const int dx[] = {0, -1, 0, 1, -1, 1, 1, -1, 0};
template<class T> inline bool chmin(T &a, T b){
    if(a > b){a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a, T b){
    if(a < b){a = b; return true;}
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    rep(i, n) {
        rep(j, m) {
            int ans = 0;
            rep(k, 9) {
                if(i + dy[k] < 0 || i + dy[k] >= n || j + dx[k] < 0 || j + dx[k] >= m) continue;
                if(s[i+dy[k]][j+dx[k]] == '#') ++ans;
            }
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}