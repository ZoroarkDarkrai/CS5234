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

    vector<int> num;
    int cur = 1, occ = 0;
    double now = 1;
    rep(i, 1000000) {
        if (occ > now) {
            cur++;
            occ = 0;
            now *= 1.1;
        }
        num.pb(cur);
        occ++;
    }

    shuffle(num.begin(), num.end(), rng);
    rep(i, 1000000) {
        //cout << num[i] << endl;
        if (i % 100 == 0) memset(seen, 0, sizeof(seen));
        if (seen[num[i]]) continue;
        seen[num[i]] = 1;
        cnt[num[i]]++;
    }
    vector<pair<int, int>> v;
    rep(i, 121) v.pb({ cnt[i + 1],i + 1 });
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (auto it : v) cout << it.sc << ' ' << it.fs << endl;
}