これは，座標降下法(coordinate descent)をC++で実装したものです
## 実行確認済み環境
OS: macOS Mojave version10.14.5
コンパイラ: Apple LLVM version 10.0.1 (clang-1001.0.46.4)

## プロジェクト構造
.  
├── README.md  
├── src  
│&nbsp;&nbsp;&nbsp;└── cd.cpp  
└── test  
&nbsp;&nbsp;&nbsp;&nbsp;└── test_cd.cpp  
    
## 依存ライブラリのインストール方法
依存ライブラリは`Eigen`のみです
1. 適当なディレクトリで `git clone https://github.com/eigenteam/eigen-git-mirror/8589bd39c42ac816419b627e49e760253d3325d0` をする
2. 中にある`Eigen`ディレクトリを`/usr/local/include`などのインクルードパスに移動させる

## テスト実行方法
`test`ディレクトリで`g++ -std=gnu++1y -O2 test_cd.cpp -o a.out && a.out`を実行する
