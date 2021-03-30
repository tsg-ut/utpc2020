// みてる: @kcz 昆布 hakatashi ナン

/*

k=1のとき:
  各隙間にどんなものを足せるかというと、勝たない手。消える。
  手が連続しているときは、2種類。連続していないときは、そのうち負ける方の1種類。
  一番最初と最後は、もとの最初と最後に勝たない手で、2種類。

  まあ、とはいえ、重複のある数え方だなぁ

  

*/
/*
昆布
R,S,P=0,1,2
処理前の文字列の階差mod3と処理後の文字列の階差数列mod3の関係
00->0 e.g. RRR->RR
01->0 e.g. RRS->RR
02->2 e.g. RRP->RP
10->1 e.g. RSS->RS
11->1 e.g. RSP->RS
12->0 e.g. RSR->RR
20->0 e.g. RPP->PP
21->0 e.g. RPR->PP
22->2 e.g. RPS->PS
> ↓outdated
> > とりあえずこの表はバグってそう(??)ナン
> > 反例ください
> > sample の SSRP(S022)を一回進めるとSRP(S22)になるので、22->2じゃないっすか
> > そうでぢた（そこだけな気もする　ちゃんと見ますが）

これを利用して復元するとO(k(k/2+|S|))
（復元中の文字列の現時点での末尾が0,1,2である場合の数みたいなのを保持する工夫は必要）
例：
新しい文字列の階差のa文字目に対応する部分まで復元した。今のところ、
古い文字列の階差はa+1文字目までできていて、
その最後の文字が0である場合の数はx通り、1である場合の数はy通り、2である場合の数はz通りだ。
さて新しい文字列の階差のa+1文字目を見てみよう。それはhogeなので、
対応する古い文字列の階差のa+1文字目とa+2文字目は(*,*),(*,*),...
これと前のステップのx,y,zを照らし合わせると新しいx,y,zが得られる

階差が同一な古い文字列の中で妥当なものは必ず1個
*/

/*
hakatashi

グー→チョキ、チョキ→パー、パー→グーを 「下り」
チョキ→グー、パー→チョキ、グー→パーを 「上り」
それ以外を「平坦」
と定義する。

k回の操作の後グーになるようなk+1文字の文字列は
上の高低を考えたときの最高点がグーであることと同値

RSRS が生まれるような文字列は存在しない?

最初がRSならK回前の文字列の戦闘も必ずRS

*/

#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<tuple>
#include <cstdint>

using u64 = std::uint64_t;

int main() {
    using namespace std;
    const auto&& S{[] {
        string S;
        cin >> S;
        vector<u64> ret(size(S));
        transform(begin(S), end(S), begin(ret), [](const auto c) {
            return 265600 % c ^ 1;
        });
        return ret;
    }()};
    u64 N{size(S)};
    u64 k;
    cin >> k;
    vector<tuple<u64, u64, u64>> now, prev;
    for (u64 i{}; i + 1 < N; ++i) {
    }
}

void zentansaku(const std::string& S, unsigned long k){
    using namespace std;
    const auto winner{[](const auto i, const auto j){
        return (i + 3 - j) % 3 ^ 1 ? i : j;
    }};
    const auto nxt{[&winner](const string& S){
        string ret;
        for(unsigned long i{0}; i + 1 < size(S); ++i)ret.push_back(winner(S[i] & 3 ^ 2, S[i + 1] & 3 ^ 2) ^ 2 | 80);
        return ret;
    }};
    unsigned long N{size(S)};
    for(unsigned long i{0}, j{[](unsigned long n){
        unsigned long r{1}, a{3};
        while(n){
            if(n & 1)r *= a;
            a *= a;
            n >>= 1;
        }
        return r;
    }(N + k)}; i < j; ++i){
        string s;
        unsigned long tmp{i};
        while(tmp){
            s.push_back(tmp % 3 ^ 2 | 80);
            tmp /= 3;
        }
        string t{s};
        for(unsigned long K{0}; K < k; ++K)t = nxt(t);
        if(t == S)cout << s << endl;
    }
}