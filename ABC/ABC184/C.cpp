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

int solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 && y1 == y2) return 0;
    if(x1+y1 == y2+x2) return 1;
    if(x1-y1 == x2-y2) return 1;
    if(abs(x1-x2)+abs(y1-y2) <= 3) return 1;
    if((x1+y1)%2 == (x2+y2)%2) return 2;
    if(abs(x1-x2)+abs(y1-y2) <= 6) return 2;
    if(abs((x1+y1) - (x2+y2)) <= 3) return 2;
    if(abs((x1-y1) - (x2-y2)) <= 3) return 2;
    return 3;
}

int main(void) {
    cout << solve() << endl;
    return 0;
}