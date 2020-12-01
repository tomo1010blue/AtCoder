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
	int n, k;
    cin >> n >> k;
    G t(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> t[i][j];
    vector<int> v(n-1);
    rep(i, n-1) v[i] = i+1;
    int cnt = 0;
    do{
        int tim = 0;
        tim += t[0][v[0]];
        repl(i, 1, n-1) {
            tim += t[v[i-1]][v[i]];
        }
        tim += t[v[n-2]][0];
        if(tim == k) ++cnt;
    }while(next_permutation(all(v)));
    cout << cnt << endl;
    return 0;
}