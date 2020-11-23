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
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    G dist(h, vector<int>(w, INF));
    queue<P> q;
    P g;
    rep(i, h) rep(j, w) {
        if(a[i][j] == 'S') {
            q.push({i, j});
            dist[i][j] = 0;
        }
    }
    vector<vector<P>> warps(256);
    rep(i, h) rep(j, w) warps[a[i][j]].eb(i, j);
    while(!q.empty()) {
        int i = q.front().fi;
        int j = q.front().se;
        q.pop();
        if(a[i][j] == 'G') {
            cout << dist[i][j] << endl;
            return 0;
        }
        rep(v, 4) {
            int ni = i + dy[v];
            int nj = j + dx[v];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if(a[ni][nj] == '#') continue;
            if(dist[ni][nj] != INF) continue;
            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni, nj});
        }
        if(islower(a[i][j])) {
            for(P p : warps[a[i][j]]) {
                int ni = p.fi;
                int nj = p.se;
                if(dist[ni][nj] != INF) continue;
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
            warps[a[i][j]] = vector<P>();
        }
    }
    cout << -1 << endl;
    return 0;
}