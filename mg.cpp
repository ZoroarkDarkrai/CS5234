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
    int cnt;

    bool operator<(const item& t1) const {
        return ((t1.id < id) || (t1.id == id && t1.cnt < cnt));
    }

};
const int k = 17;
const int p = 2900;
bitset<p> bf;
set<item> c;

const int nItems = 1000000;
const int tSize = 100;


const int w = 2;

int a[k], b[k];
bool cnt[p][p];

bool check(int x) {
    rep(i, k) {
        int res = (a[i] * x + b[i]) % p;
        if (!bf[res]) return false;
    }
    return true;
}

void setBf(int x) {
    rep(i, k) {
        int res = (a[i] * x + b[i]) % p;
        bf[res] = 1;
    }
}


int main(int argc, char** argv) {
    int n = stoi(argv[1]);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    rep(i, k) {
        int aa = rand() % p, bb = rand() % p;
        while (cnt[aa][bb]) aa = rand() % p, bb = rand() % p;
        cnt[aa][bb] = 1;
        a[i] = aa;
        b[i] = bb;
    }

    rep(i, nItems) {
        int cur;
        cin >> cur;

        if (check(cur)) continue;
        setBf(cur);

        bool f = 0;

        for (auto it : c) {
            if (it.id == cur) it.cnt++, f = 1;
        }

        if (f) continue;
        if (c.size() < n) {
            c.insert({ cur, 1 });
            continue;
        }
        for (auto it : c) {
            it.cnt--;
            if (it.cnt == 0) c.erase(it);
        }


        if (i % tSize) {
            bf.reset();
        }
    }

    int cnt = 0;

    for (auto it : c) {
        if (it.id > n) cnt++;
    }

    cout << cnt << endl;
}