// ------------------------- MLong -------------------------
template<typename T>
T power(T a, i64 b) {
    T res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

template<i64 M>
struct MLong {
    i64 x;
    constexpr MLong() : x(0) {}
    template <typename U> MLong(const U y) { x = normalize(y % M); }

    i64 normalize(i64 y) {
        if (y < 0) {
            y += M;
        }
        if (y >= M) {
            y -= M;
        }
        return y;
    }
    explicit operator i64() const {
        return x;
    }
    MLong inv() const {
        return power(MLong(x), M - 2);
    }
    MLong operator-() const {
        MLong res;
        res.x = normalize(-x);
        return res;
    }
    MLong& operator+=(MLong rhs) {
        x = normalize(x + rhs.x);
        return *this;
    }
    MLong& operator-=(MLong rhs) {
        x = normalize(x - rhs.x);
        return *this;
    }
    MLong& operator*=(MLong rhs) {
        x = x * rhs.x % M;
        return *this;
    }
    MLong& operator/=(MLong rhs) {
        return *this *= rhs.inv();
    }
    friend MLong operator+(MLong lhs, const MLong& rhs) { return lhs += rhs; }
    friend MLong operator-(MLong lhs, const MLong& rhs) { return lhs -= rhs; }
    friend MLong operator*(MLong lhs, const MLong& rhs) { return lhs *= rhs; }
    friend MLong operator/(MLong lhs, const MLong& rhs) { return lhs /= rhs; }

    friend bool operator==(const MLong& lhs, const MLong& rhs) { return lhs.x == rhs.x; }
    friend bool operator!=(const MLong& lhs, const MLong& rhs) { return lhs.x != rhs.x; }

    friend std::istream& operator>>(std::istream& is, MLong& a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const MLong& a) {
        return os << a.x;
    }
};

constexpr i64 mod = 998244353;
using Z = MLong<mod>;