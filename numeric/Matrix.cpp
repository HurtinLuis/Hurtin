// ------------------------- Martrix -------------------------
template<typename T>
struct Matrix : public std::vector<std::vector<T>> {
    int n;
    Matrix(int n_ = 0, int op = 0) : n(n_) {
        this->assign(n, std::vector<T>(n));
        if (op) for (int i = 0; i < n; i++) (*this)[i][i] = 1;
    }
};

template<typename T>
Matrix<T> operator*(const Matrix<T> &a, const Matrix<T> &b) {
    assert(a.size() == b.size());
    int n = a.size();
    Matrix<T> c(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

template<typename T>
Matrix<T> &operator*=(Matrix<T> &a, const Matrix<T> &b) {
    return a = a * b;
}

template<typename T, typename U>
Matrix<T> power(const Matrix<T> &a, U b) {
    int n = a.size();
    Matrix<T> res(n, 1), x = a;
    while (b) {
        if (b & 1) res *= x;
        x *= x;
        b >>= 1;
    }
    return res;
}

using Mat = Matrix<Z>;
