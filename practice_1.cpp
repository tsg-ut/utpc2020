#include <iostream>
#include <cstdint>
#include <string>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main() {
    int32_t a, b, c;
    string s;
    cin >> a >> b >> c;
    cin >> s;

    mint ia = mint(a).inv();
    mint ib = mint(b).inv();
    mint ic = mint(c).inv();

    cout << ((ia * ib + ib * ic + ic * ia) / (ia * ib * ic)).val() << " " << s << endl;

    return 0;
}