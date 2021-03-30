/*
みてる: fabon hakatashi naan
書いてる: hakatashi
提出→WA https://atcoder.jp/contests/utpc2020/submissions/21279502


操作1: 和が1減る、整数の個数は変わらず
操作2: 整数の個数が1減る、和は変わらず
→ 数と和を考えれば操作1と操作2の回数が分かる


小さい数をどう処理するかが問題
* 1 INF INF INF => 16 は無理
* なので小さい数には小さい数をぶつけたくて
* ソートして小さい数順に貪欲で行ける?

問題は「大きい数はどうとでもなる」かどうか
* 3 INF => 3 はいける?
  * いける
  * いけるのでは
* 3 INF => 8 は無理

貪欲だと難しいパターンとして
* 3 4 5 6 => 5 13 とか
  * 3 4 まで見た段階で5とぶつけるとだめ
  * このパターンでも3まで見た段階で4とmergeするのは常に正しいはず
* mergeしたあとしかるべき場所に挿入すれば良い?
  * 3 4 5 6 => 5 13 が 5 6 7 => 5 13 になると考える
  * 平衡二分探索木が必要

とりあえずここまでの方針で書いてみてます
→書いた

反例: 2 2 3 3 => 5 5


3 3 3 3 3 3 3 3 5 => 5 24

2 2 3 3 => 4 6
2 2 3 3 => 5 5
*/

#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        vector<int64_t> as = {};
        vector<int64_t> bs = {};
        multiset<int64_t> tree;
        int n, m;

        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            int64_t a;
            cin >> a;
            as.push_back(a);
            tree.insert(a);
        }
        for (int j = 0; j < m; j++) {
            int64_t b;
            cin >> b;
            bs.push_back(b);
        }

        sort(bs.begin(), bs.end());

        bool ok = true;
        while (!bs.empty()) {
            if (tree.empty()) {
                ok = false;
                break;
            }

            int64_t first = *tree.begin();
            tree.erase(tree.begin());

            if (first >= bs[0]) {
                bs.erase(bs.begin());
                continue;
            }

            if (tree.empty()) {
                ok = false;
                break;
            }

            int64_t second = *tree.begin();
            tree.erase(tree.begin());

            int64_t new_value = first;
            if (first == second) {
                new_value += second;
            } else {
                new_value += first + 1;
            }

            tree.insert(new_value);
        }

        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}