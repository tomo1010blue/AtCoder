#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
using mint = modint1000000007;
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

int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> syougen(n, vector<int>(n, -1));
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            --x;
            syougen[i][x] = y;
        }
    }
    int ans = 0;
    rep(i, 1 << n) {
        vector<int> d(n);
        rep(j, n) {
            if(i >> j & 1) d[j] = 1;
        }
        bool ok = true;
        rep(j, n) {
            if(!d[j]) continue;
            rep(k, n) {
                if(syougen[j][k] == -1) continue;
                if(syougen[j][k] != d[k]) ok = false;
            }
        }
        if(ok) chmax(ans, __builtin_popcount(i));
    }
    cout << ans << endl;
    return 0;
}