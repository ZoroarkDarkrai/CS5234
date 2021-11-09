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

struct item {
    int id;
    int cnt = 0;
    bool state = 1;
};
const int n = 15;
vector<item> b[n];
item c[n];

const int nItems = 1000000;
const int tSize = 100;

unsigned int hsh(unsigned int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

const int w = 2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(i, nItems) {
        unsigned int cur;
        cin >> cur;
        unsigned int hCur = hsh(cur) % n;

        bool f = 0;
        for (auto it : b[hCur]) {
            if (it.id == cur) {
                if (it.state) {
                    it.state = 0;
                    it.cnt++;
                }
                f = 1;
                break;
            }
        }
        if (f) continue;

        if (b[hCur].size() < w) {
            b[hCur].pb({ cur, 1, 1 });
            continue;
        }

        if (c[hCur].state) continue;

        c[hCur].state = 0;
        c[hCur].cnt++;

        for (auto it : b[hCur]) {
            if (it.cnt < c[hCur].cnt) {
                c[hCur].id = cur;
                swap(it, c[hCur]);
                break;
            }
        }

        if (i % tSize) {
            rep(i, n) {
                c[i].state = 1;
                for (auto it : b[i]) it.state = 1;
            }
        }
    }

    int cnt = 0;

    rep(i, n) {
        for (auto it : b[i]) {
            if (it.id > 2 * n) cnt++;
        }
    }

    cout << cnt << endl;
}