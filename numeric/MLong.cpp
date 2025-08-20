// ------------------------- MLong -------------------------
template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a, std::swap(a, m);
        u -= t * v, std::swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<typename T, typename U>
T power(T a, U b) {
    assert(b >= 0);
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
    constexpr MLong() : x() {}
    template <typename U> MLong(const U &v) { x = normalize(i64(v)); }

    i64 normalize(i64 y) {
        y %= M;
        return (y < 0 ? y + M : y);
    }

    explicit operator i64() const {
        return x;
    }

    MLong inv() const {
        return MLong(inverse(x, M));
    }
    MLong operator-() const {
        MLong res;
        res.x = normalize(M - x);
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

// constexpr i64 mod = i64(1E18) + 9;
constexpr i64 mod = 998244353;
using Z = MLong<mod>;
