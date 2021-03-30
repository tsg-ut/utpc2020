/*
済
みてる: hakatashi、北京原人
わからん hakatashi

行列が与えられるので、以下の条件を満たす同じ大きさの行列M個を構築
* 全ての成分は絶対値が40以下の整数
  * Aの成分を適切に-1倍したものをBとして使える
  * 2倍や1/2倍はできないこともある
* 行列式がすべてもとの行列と等しい
* M個の総和を取るともとの行列の対角成分のM倍になっている
  * 総和の対角成分以外は全部0じゃないといけない（対角行列）


Aのi行目を-1倍、i列目を-1倍したとき、対角成分も行列式も変わらない
Aのi行目を-1倍、j列目を-1倍したときは行列式だけ変わらない
Aの偶数個の行または偶数個の列を-1倍したときは、行列式だけ変わらない
これらをBとして利用できるかも
*/
/*
昆布
Aのある行(resp. 列)のスカラー倍を別の行(resp. 列)に足したときは、行列式だけ変わらない
ここで条件を緩めてその行自身にも足して良いことにすると作れる行列の全体は格子とかになる？
その格子の中で行列式が元通りである条件は何？
*/

// やるぞ〜〜〜 ナン
/*
適当にいっぱいやったらどうせ合計が0になるという気持ちでやると実際なる
*/