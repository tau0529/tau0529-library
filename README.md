# tau0529-library

競プロ用の自作C++ライブラリです。

## ファイル構成

| ファイル | 内容 |
|---|---|
| `base.hpp` | 標準ライブラリ・ACLの読み込み |
| `bigint.hpp` | 多倍長整数 |
| `build.py` | ライブラリの自動結合 |
| `data_structures.hpp` | その他のデータ構造 |
| `io.hpp` | vector・pairなどSTLコンテナの入出力 |
| `math.hpp` | 組合せ・素数など |
| `operators.hpp` | vector・pairの演算子 |
| `seg_tree.hpp` | セグメント木・遅延セグメント木 |
| `template.cpp` | 提出用の統合テンプレート |
| `utilities.hpp` | 型エイリアス・マクロ・定数・便利関数 |

`base.hpp`以外の`.hpp`ファイルは、すべて`base.hpp`を読み込む構成になっています。
その他の .hpp ファイル間には依存関係を設けていません。

## 使い方

### テンプレートの生成

リポジトリのディレクトリで以下を実行します。

```bash
python3 build.py
```

各ライブラリが結合され、`template.cpp` が生成されます。

### コンパイル

```bash
g++ -std=c++20 -O2 template.cpp -o main
```

## 注意事項

- 動作確認を行ったうえで更新していますが、すべての動作を保証するものではありません。
- バグや不具合を発見した場合は報告していただけると助かります。

## 機能紹介

<details>
<summary><b><code>base.hpp</code> — ベース</b></summary>
  
  `bits/stdc++.h`をインクルードして`using namespace std;`しています

  ACLが読み込める場合も同様に全部インクルードして`using namespace atcoder;`です

  ACLが読み込める場合は`HAS_ACL`を1に、読み込めない場合は0にしています

</details>

<details>
<summary><b><code>io.hpp</code> — 入出力</b></summary>

- 多次元`vector`の受け取り
- <details>
  <summary>多次元<code>vector</code>の出力</summary>

  2次元以降は改行が1つずつ増えます

  例

  ```cpp
  vector<vector<vector<vector<int>>>> v = {
      {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}},
      {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}
  };
  cout << v;
  ```

  ```text
  1 2
  3 4

  5 6
  7 8


  9 10
  11 12


  13 14
  15 16
  ```
  </details>
- <details>
  <summary>複数の<code>vector</code>の同時受け取り - <code>vcin</code></summary>

  各行に $A_i\ B_i$ のように複数の数値が与えられる際にそれぞれを別の`vector`にまとめて受け取れます

  入力例

  ```txt
  3
  1 2
  1 3
  2 3
  ```

  に対し以下のようなコードで受け取れます

  ```cpp
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  vcin(A, B);
  //A = {1, 1, 2}  B = {2, 3, 3}
  ```

  </details>
- <details>
  <summary>ジャグ配列の受け取り - <code>jagcin</code></summary>

  ジャグ配列を受け取れます

  入力例

  ```txt
  3
  3 1 2 3
  2 1 3
  5 3 2 1 4 3
  ```

  に対し以下のようなコードで受け取れます

  ```cpp
  int N;
  cin >> N;
  vector<vector<int>> L(N);
  jagcin(L);
  //L = {{1, 2, 3}, {1, 3}, {3, 2, 1, 4, 3}}
  ```

  </details>
- `pair`の受け取り
- <details>
  <summary><code>pair</code>の出力</summary>
  
  `(first, second)`という形式で出力します

  </details>
- <details>
  <summary><code>map</code>, <code>unordered_map</code>の受け取り - <code>mapcin</code></summary>

  `mapcin(M, N)`とすると`N`個`key`と`value`を受け取ります

  重複している場合後者が優先されます

  </details>
- <details>
  <summary><code>map</code>, <code>unordered_map</code>の出力</summary>

  `key:value`という形式で半角スペース区切りで出力します

  </details>
- <details>
  <summary><code>set</code>, <code>multiset</code>, <code>unordered_set</code>の受け取り - <code>setcin</code></summary>

  `setcin(S, N)`とすると`N`個受け取り`insert`します
  
  </details>
- `set`, `multiset`, `unordered_set`の出力
- <details>
  <summary><code>queue</code>, <code>priority_queue</code>, <code>deque</code>の受け取り - <code>queuecin</code></summary>

  `queuecin(Q, N)`とすると`N`個受け取り`push`/`push_back`します

  `deque`に限り`dequecin(Q, N)`でも動作します
  
  </details>
- <details>
  <summary><code>queue</code>, <code>priority_queue</code>, <code>deque</code>の出力</summary>
  
  `queue`, `deque`なら`front`から、`priority_queue`なら`top`から順に半角スペース区切りで出力します

  </details>
- <details>
  <summary><code>stack</code>の受け取り - <code>stackcin</code></summary>

  `stackcin(S, N)`とすると`N`個受け取り`push`します

  </details>
- <details>
  <summary><code>stack</code>の出力</summary>
  
  `top`から順に半角スペース区切りで出力します
  
  </details>
- <details>
  <summary><code>modint</code>の受け取り</summary>

  ACLがinclude出来ている場合`modint`を直接受け取れるようにします

  `modint998244353`, `modint1000000007`, `modint`どれでも動きます
  
  </details>
- <details>
  <summary><code>modint</code>の出力</summary>

  ACLがinclude出来ている場合`modint`の値を`.val()`で出力します
  
  </details>
</details>

<details>
<summary><b><code>operators</code> ― オペレーター</b></summary>

- <details>
  <summary><code>vector</code>と定数の四則演算が出来ます</summary>

  四則演算と複合代入演算子、インクリメントデクリメントをオーバーロードしています

  例

  ```cpp
  vector<int> L = {1, 2, 4, 7};
  L += 3; // L = {4, 5, 7, 10}
  L %= 4; // L = {0, 1, 3, 2}
  L--; // L = {-1, 0, 2, 1}
  cout << 2 * L << endl; // -2 0 4 2
  ```

  </details>
</details>
