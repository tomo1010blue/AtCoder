#include <bits/stdc++.h>
#include <atcoder/all>
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
using P = pair<double, double>;
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
	string s;
    cin >> s;
    int n = s.size();
    vector<vector<mint>> dp(n+1, vector<mint> (13));
    dp[0][0] = 1;
    rep(i, n) {
        int c;
        if(s[i] == '?') c = -1;
        else c = s[i] - '0';
        rep(j, 10) {
            if(c != -1 && c != j) continue;
            rep(ki, 13) {
                dp[i + 1][(ki * 10 + j) % 13] += dp[i][ki];
            }
        }
    }
    cout << dp[n][5].val() << endl;
    return 0;
}