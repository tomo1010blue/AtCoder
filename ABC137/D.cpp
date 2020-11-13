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
	int n, m;
    cin >> n >> m;
    G jobs(m);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        if(a > m) continue;
        jobs[m-a].pb(b);
    }
    priority_queue<int> q;
    ll ans = 0;
    for(int i = m - 1; i >= 0; --i) {
        for(int b : jobs[i]) {
            q.push(b);
        }
        if(!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}