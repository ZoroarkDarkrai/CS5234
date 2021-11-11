#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define ll long long 
#define fs first
#define sc second
#define MAXN 1000005
#define lsb(x) (x&(-x))
#define endl '\n'
#define pb push_back
using namespace std;

std::mt19937 rng(150101);
int cnt[122];
bool seen[122];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(i, 1000000) {
        int cur = 1;
        while (((double)rng() / UINT_MAX) <= 0.9) {
            cur++;
        }
        //cout << cur << endl;
        if (i % 100 == 0) memset(seen, 0, sizeof(seen));
        if (seen[cur]) continue;
        seen[cur] = 1;
        cnt[cur]++;
    }
    vector<pair<int, int>> v;
    rep(i, 121) v.pb({ cnt[i + 1],i + 1 });
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (auto it : v) cout << it.sc << ' ' << it.fs << endl;
}