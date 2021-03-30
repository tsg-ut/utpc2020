// やってる: @sh_mug
// 済

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using P = pair<int, int>;

bool simulation (long long t, vector<P> &xa) {
    auto t0 = t;
    // if (t0 < 10) cerr << "t0=" << t0 << endl;
    for (int i = 0, n = xa.size(); i < n; ++i) {
        // if (t0 < 10)cerr << t << endl;
        auto &[x, a] = xa[i];
        if (i > 0 && t < t0) {
            t = min(t0, t + x - xa[i - 1].first);
        }
        t -= a;
        if (t < 0) return false;
    }
    return true;
}

int main() {
    int n, l;
    cin >> n >> l;
    vector<P> xa(n);
    for (auto &[x, a] : xa) {
        cin >> x >> a;
    }
    long long ng = 0, ok = 1e18;
    while (ok - ng > 1) {
        long long med = (ng + ok) / 2;
        (simulation(med, xa) ? ok : ng) = med;
    }
    cout << ok << endl;
    return 0;
}