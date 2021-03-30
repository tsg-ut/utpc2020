/*
済

見てる：北京原人 ふぁぼん

制限時間：1sec　です。
正解者がわりといます。簡単かもしれません。

ある列や行について、一度全て同じ色になればいつでも削除できる。
貪欲に考えて、全て色が同じ行または列があれば削除するということを繰り返せばいいのだが、愚直な実装だと多分間に合わない。
    * 「あえて削除しない」という行為に意味がないので(どうせ後で削除しても同じ)、貪欲でいけそう

貪欲というのは例えば以下のようなものです。
1.全ての行を見る。→同じ色の行を全て削除
2.全ての列を見る。→同じ色の列を全て削除
1.と2.を2000回ずつ交互に繰り返す

今の行と列の個数を保持しておいて、黒を-1で白を1で削除済みを0とすれば削除はなんかいい感じにできたりしませんか 知らんけど
これだと列や行の和が-nまたはnの列が「全部揃ってる」となる
一瞬imos法(二次元累積和)……?みたいな気持ちになった いけるか今考えていますが
削除するとこが全部揃ってるから「この列/行全部に+1/-1」すれば0にできますね

冷静に考えると二次元のデータを保持をしなくても、各列・行の和を保持して、列を削除するときは行の和を全部+1/-1(行を削除するときは列の和を全部+1/-1)すればよさそう?
そもそも「全体加算」はたかだか4000回しか起きないんだから、累積和とかしなくても愚直に「全部ループで+1か-1する」でよさそう
*/