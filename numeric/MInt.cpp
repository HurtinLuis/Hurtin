constexpr int M = 998244353;

inline int normalize(i64 x) {
    x %= M;
    return (x < 0 ? x + M : x);
}

inline int add(int x, int y) { return normalize(x + y); }
inline int sub(int x, int y) { return normalize(x - y); }
inline int mul(int x, int y) { return normalize(1LL * x * y); }

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int a) { return power(a, M - 2); }
