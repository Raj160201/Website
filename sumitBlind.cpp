#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

const int N = 1e5+5;

int n, m, q;
vector<int> p[N];
unordered_set<long long> s[N];

long long hashf(vector<int>& v) {
    const int M = 998244353;
    long long h = 0;
    for (int i=0;i<v.size();i++) {
        h = (h * 31 + v[i]) % M;
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            int c, ind;
            cin >> c >> ind;
            p[ind].push_back(c);
        } else {
            int i, j;
            cin >> i >> j;
            if (p[i].size() != p[j].size()) {
                cout << 0 << endl;
                continue;
            }
            if (s[i].count(hashf(p[j]))) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        s[i].insert(hashf(p[i]));
    }
    cin >> q;
    int ans = 0;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if (p[x].size() != p[y].size()) {
            continue;
        }
        if (s[x].count(hashf(p[y]))) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
