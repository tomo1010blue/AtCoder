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
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> fox;
    rep(i, n) {
        fox.push(s[i]);
        if(fox.size() < 3) continue;
        string t = "";
        rep(i, 3) {
            t += fox.top();
            fox.pop();
        }
        if(t == "xof") continue;
        rep(i, 3) fox.push(t[2-i]);
    }
    cout << fox.size() << endl;
    return 0;
}