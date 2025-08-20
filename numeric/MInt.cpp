// ------------------------- MInt -------------------------
template<typename T, typename U>
constexpr T power(T a, U b) {
    assert(b >= 0);
    T res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

template<int M>
struct MInt {
    int x;
    constexpr MInt() : x() {}
    constexpr MInt(i64 x) : x(normalize(x)) {}

    template<typename T>
    static constexpr int normalize(T x) {
        int y = x % M;
        return (y < 0 ? y + M : y);
    }
    explicit operator int() const {
        return x;
    }
    MInt inv() const {
        assert(x != 0);
        return power(*this, M - 2);
    }

    MInt operator-() const {
        MInt res;
        res.x = normalize(-x);
        return res;
    }
    MInt &operator+=(MInt rhs) & {
        x = normalize(x + rhs.x);
        return *this;
    }
    MInt &operator-=(MInt rhs) & {
        x = normalize(x - rhs.x);
        return *this;
    }
    MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % M;
        return *this;
    }
    MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }

    friend MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend bool operator==(MInt lhs, MInt rhs) {
        return lhs.x == rhs.x;
    }
    friend bool operator!=(MInt lhs, MInt rhs) {
        return lhs.x != rhs.x;
    }

    friend std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.x;
    }
};

template<int V, int P>
constexpr MInt<P> inverse = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;
