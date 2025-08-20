constexpr i64 M = 998244353;

inline i64 normalize(i64 x) {
    x %= M;
    return (x < 0 ? x + M : x);
}

inline i64 add(i64 x, i64 y) { return normalize(x + y); }
inline i64 sub(i64 x, i64 y) { return normalize(x - y); }
inline i64 mul(i64 x, i64 y) { return normalize(x * y); }

i64 power(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
i64 inv(i64 a) { return power(a, M - 2); }
