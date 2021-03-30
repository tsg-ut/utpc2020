/*
みてる hakatashi ふぁぼん sh-mug
検討もつかない

1回の魔法で倒す数をあえて少なくする必要はなさそう。
DP? 私(ふぁぼん)めちゃくちゃDP苦手で無理……

雑に気付いたことを並べてみる
* 解の上界は Σ ceil(Ai / K)
* [K匹まで]を[K匹]にして、すべての要素が0以下になるようにしてもよい
* X <= Yなら、スキル1だけを使うとよい？←嘘。例 2 2 1 1 3 3
* LPに持ち込むにしても、ベクトルがn+nCk本必要になりそう？
    * 双対は取れる？←取ったところで複雑さは変わらなさそうでした。没
* スキル2だけを使う場合の最小値は求められますか？
    * max(ceil Σ Ai/K, max Ai)とかだったりしないかな
    * これをO(X)で計算できると、Aiをpriority_queueで管理して全体O(Xlogn * Σ ceil(Ai / K))で求められる。だめじゃん
    * 100000 1 1 1 100000 100000 ... 100000 みたいなケースを高速に処理したい
*/

#include <bits/stdc++.h>

int main() {
    using namespace std;
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    vector<int> a(n);
    for (auto &e : a) cin >> e;

    priority_queue<int> pq(a.begin(), a.end());
    int sum = reduce(a.begin(), a.end());
    int ans = max((sum + k - 1) / k, pq.top()) * y;
    int cnt = 0;
    while (pq.top() > 0) {
        int t = pq.top(), dt = min(t, k);
        pq.pop();
        pq.push(t - dt);
        sum -= dt;
        ans = min(ans, ++cnt * x + max((sum + k - 1) / k, pq.top()) * y);
    }
    cout << ans << "\n";
    return 0;
}