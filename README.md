# tau0529-library

競技プロ用の自作C++ライブラリです。

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

## 主な機能

<details>
<summary><b>io.hpp — 入出力</b></summary>

- 多次元vectorの受け取り
多次元ベクターの出力
```cpp
vector<vector<vector<int>>> v = {
    {{1, 2}, {3, 4}},
    {{5, 6}, {7, 8}}
};
cout << v;
```


</details>
