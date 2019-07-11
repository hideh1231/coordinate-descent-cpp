#include <Eigen/Core>
using Eigen::ArrayXi;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::VectorXi;

float sign(float in)
{
    if (in > 0)
        return 1;
    else if (in < 0)
        return -1;
    else
        return 0;
}

float soft_threshold(float X, const float thresh)
{
    if (abs(X) <= thresh)
    {
        return 0.0;
    }
    else
    {
        return X - thresh * sign(X);
    }
}

VectorXd coordinate_descent(const MatrixXd &X, const VectorXd &y, float alpha = 1.0, int n_iter = 1000)
{
    int n_samples = X.rows();
    int n_features = X.cols();
    VectorXd w = VectorXd::Zero(n_features);
    while (n_iter--)
    {
        for (size_t j = 0; j < n_features; ++j)
        {
            w(j) = 0.0;
            VectorXd r_j = y - X * w;
            w(j) = soft_threshold(X.col(j).dot(r_j) / n_samples, alpha);
        }
    }
    return w;
}