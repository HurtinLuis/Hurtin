constexpr int mod = 998244353;

inline int add(int x, int y) {x += y; return x >= mod ? x - mod : x;}
inline int sub(int x, int y) {x -= y; return x < mod ? x + mod : x;}
inline int mul(int x, int y) {return 1LL * x * y % mod;}

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {return power(a, mod - 2);}


using poly = std::vector<int>;

void fft(poly &a, bool invert = false) {
    int n = len(a);
    assert((mod - 1) % n == 0);
    poly b(n);
    for (int d = n / 2; d; d /= 2, swap(a, b)) {
        int w = power(3, (mod - 1) / n * d), m = 1;
        for (int i = 0; i < n; i += d * 2, m = mul(m, w)) {
            for (int j = 0; j < d; j++) {
                int u = a[i + j], v = mul(a[i + j + d], m);
                b[i / 2 + j] = add(u, v);
                b[i / 2 + j + n / 2] = sub(u, v);
            }
        }
    }
    if (invert) {
        reverse(a.begin() + 1, a.end());
        int z = inv(n);
        for (auto& t : a) t = mul(t, z);
    }
}

// poly operator+(const poly &a, const poly &b) {
//     poly res = a;
//     res.resize(std::max(len(a), len(b)));
//     for (int i = 0; i < len(b); i++) {
//         res[i] = add(res[i], b[i]);
//     }
//     return res;
// }

// poly operator-(const poly &a, const poly &b) {
//     poly res = a;
//     res.resize(std::max(len(a), len(b)));
//     for (int i = 0; i < len(b); i++) {
//         res[i] = sub(res[i], b[i]);
//     }
//     return res;
// }

poly operator*(poly a, poly b) {
    if (a.empty() || b.empty()) {
        return {};
    }
    int n = 1, m = len(a) + len(b) - 1;
    while (n < m) {
        n *= 2;
    }
    a.resize(n), fft(a);
    b.resize(n), fft(b);
    for (int i = 0; i < n; i++) {
        a[i] = mul(a[i], b[i]);
    }
    fft(a, true), a.resize(m);
    return a;
}
