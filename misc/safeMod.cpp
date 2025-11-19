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
