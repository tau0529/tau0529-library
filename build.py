
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parent
OUTPUT = ROOT / "template.cpp"

# 結合するファイル（順番も指定）
FILES = [
    "base.hpp",
    "prototype.hpp",
    "vector.hpp",
    "pair.hpp",
    "stl.hpp",
    "utilities.hpp",
    "seg_tree.hpp",
    "math.hpp",
    "bigint.hpp",
    "data_structures.hpp",
]

included = set()
pattern = re.compile(r'^\s*#\s*include\s*"([^"]+)"\s*$')


def expand(filename):
    path = (ROOT / filename).resolve()

    if path in included:
        return ""

    if not path.is_file():
        raise FileNotFoundError(path)

    included.add(path)
    result = []

    for line in path.read_text(encoding="utf-8").splitlines():
        if line.strip() == "#pragma once":
            continue

        match = pattern.match(line)

        if match:
            result.append(expand(match.group(1)))
        else:
            result.append(line)

    return "\n".join(result) + "\n"


code = "\n".join(expand(name) for name in FILES).lstrip("\n")

# 初期段階ではテスト用main関数を付ける
code += """
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
"""

OUTPUT.write_text(code, encoding="utf-8")
print(f"生成完了: {OUTPUT}")
print(f"文字数: {len(code)}")

# 実行 python3 build.py