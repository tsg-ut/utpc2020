// 済
// 昆布 sh-mug naan
/*
# 問題の言いかえ
すべてのiについて(0-based index)
P_i = M_iの逆数
dp[i][j] = (P_i ... P_{n-1}から相異なるj個を選んだものの積)の総和
ただし、dp[i][0] = 1, dp[i][j] = 0 (if i + j > n)
として、(dp[1][k-1] + ... + dp[n][k-1]) / binom(n, k) が答え
これを高速に計算できるとよい
> これ以上はわかりません...たすけてー

> i大→小　の順で計算すると過去の計算が使えそう 昆布
> FFTなのか？また……？（何も考えずにいう） 昆布
> A_iを求めるのにFFTを使うだけだとO(N^2)（しかしdp抜きでできる） 昆布
> P全体からK-1個選んだものに、一番左のアイドルの持っている服の数だけ傾斜をかけて足す方法はないか

> FFTかな〜やっぱ笑 ナン
*/

#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = modint998244353;

// binomial coefficients
constexpr int FAC_MAX = 100001;
array<mint, FAC_MAX> fac, finv, inv;
void mod_init (void) {
    int MOD = modint::mod();
    fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
    for (int i = 2; i < FAC_MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = - inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}
mint binom (int a, int b) {
    if (a < b) return 0;
    if (a < 0 || b < 0) return 0;
    return fac[a] * finv[b] * finv[a - b];
}

int main (void) {
    mod_init();
    int n, k;
    cin >> n >> k;
    vector<int> m(n);
    for (auto &x : m) cin >> x;

    sort(m.begin(), m.end());
    vector<mint> m_rev(n);
    transform(m.begin(), m.end(), m_rev.begin(), [](int x)->mint{ return mint(x).inv(); });
    mint res = 0;
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1));
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; i + j <= n; ++j) {
            dp[i][j] = dp[i + 1][j] + dp[i + 1][j - 1] * m_rev[i];  // DPテーブル
        }
    }
    vector<mint> a(n);
    for (int i = 0; i < n; ++i) a[i] = dp[i + 1][k - 1];
    cout << (reduce(a.begin(), a.end()) / binom(n, k)).val() << endl;
    return 0;
}