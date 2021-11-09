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

int zipf(double alpha, int n)
{
    static int first = 1;      // Static first time flag
    static double c = 0;          // Normalization constant
    static double* sum_probs;     // Pre-calculated sum of probabilities
    double z;                     // Uniform random number (0 < z < 1)
    int zipf_value;               // Computed exponential value to be returned
    int    i;                     // Loop counter
    int low, high, mid;           // Binary-search bounds

    // Compute normalization constant on first call only
    if (first)
    {
        for (i = 1; i <= n; i++)
            c = c + (1.0 / pow((double)i, alpha));
        c = 1.0 / c;

        sum_probs = (double*)malloc((n + 1) * sizeof(double));
        sum_probs[0] = 0;
        for (i = 1; i <= n; i++) {
            sum_probs[i] = sum_probs[i - 1] + c / pow((double)i, alpha);
        }
        first = 0;
    }

    // Pull a uniform random number (0 < z < 1)
    do
    {
        z = (double)rng() / UINT_MAX;
    } while ((z == 0) || (z == 1));

    // Map z to the value
    low = 1, high = n, mid;
    do {
        mid = floor((low + high) / 2);
        if (sum_probs[mid] >= z && sum_probs[mid - 1] < z) {
            zipf_value = mid;
            break;
        } else if (sum_probs[mid] >= z) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } while (low <= high);


    // Assert that zipf_value is between 1 and N
    assert((zipf_value >= 1) && (zipf_value <= n));

    return(zipf_value);
}

int cnt[122];
bool seen[122];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> num;
    rep(i, 1000000) {
        num.pb(zipf(0.5, 121));
        cnt[num[i]]++;
    }

    shuffle(num.begin(), num.end(), rng);
    //rep(i, 1000000) cout << num[i] << endl;

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