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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    queue<char> qa, qb, qc;
    rep(i, sz(a)) qa.push(a[i]);
    rep(i, sz(b)) qb.push(b[i]);
    rep(i, sz(c)) qc.push(c[i]);
    char s = qa.front();
    qa.pop();
    while(1) {
        if(s == 'a') {
            if(qa.empty()) {
                cout << 'A' << '\n';
                return 0;
            }
            s = qa.front();
            qa.pop();
        } else if(s == 'b') {
            if(qb.empty()) {
                cout << 'B' << '\n';
                return 0;
            }
            s = qb.front();
            qb.pop();
        } else if(s == 'c') {
            if(qc.empty()) {
                cout << 'C' << '\n';
                return 0;
            }
            s = qc.front();
            qc.pop();
        }
    }
    return 0;
}