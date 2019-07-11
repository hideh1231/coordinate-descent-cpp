#include <random>
#include <iostream>
#include <cstdio>
#include <chrono>
#include "../src/cd.cpp"

// 特徴量の次元
int n_features = 1000;
// サンプル数
int n_samples = 100;
// 非ゼロの特徴量の数
int n_nonzero_coefs = 20;
// イテレーションの回数
int n_iter = 1000;
// 正則化パラメータ
float alpha = 0.6;

int main()
{
    auto start = std::chrono::system_clock::now();
    std::mt19937 mt(0);

    std::uniform_int_distribution<int> rnd(0, n_features);
    VectorXi idx(n_nonzero_coefs);
    for (int i = 0; i < n_nonzero_coefs; ++i)
    {
        idx(i) = rnd(mt);
    }
    VectorXd w = VectorXd::Zero(n_features);
    std::normal_distribution<> norm(0.0, 1.0);
    for (int i = 0; i < w(idx).size(); ++i)
    {
        float a = w(idx(i)) = norm(mt);
    }

    MatrixXd X(n_samples, n_features);
    for (int i = 0; i < n_samples; ++i)
    {
        for (int j = 0; j < n_features; ++j)
        {
            X(i, j) = norm(mt);
        }
    }
    VectorXd y = X * w;
    for (int i = 0; i < y.rows(); ++i)
    {
        y(i) += norm(mt);
    }

    VectorXd w_pred = coordinate_descent(X, y, alpha, n_iter);

    printf("Number of nonzero coefficients (true) : %ld\n", (w.array() != 0).count());
    printf("Number of nonzero coefficients (predicted) : %ld\n", (w_pred.array() != 0).count());

    printf("Euclidean distance between coefficients : %lf\n", (w - w_pred).norm());
    printf("Euclidean distance between estimated output : %lf\n", (y - X * w_pred).norm());

    auto end = std::chrono::system_clock::now();
    auto dur = end - start;
    auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    printf("%f[s]\n", (float)msec / 1000.0);
}
