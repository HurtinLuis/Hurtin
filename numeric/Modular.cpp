// ------------------------- Modular -------------------------
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

template <typename T>
class Modular {
public:
    using Type = typename std::decay<decltype(T::value)>::type;
    
    constexpr Modular() : x() {}
    template <typename U> Modular(const U& v) { x = normalize(v); }
    
    template <typename U>
    static Type normalize(const U& y) {
        Type v;
        if (mod() <= y && y < mod()) {
            v = static_cast<Type>(y);
        } else {
            v = static_cast<Type>(y % mod());
        }
        return (v < 0 ? v + mod() : v);
    }
    
    Type val() const { return x; }
    template <typename U> explicit operator U() const { return static_cast<U>(x); }
    
    constexpr static Type mod() { return T::value; }
    Modular inv() const { return Modular(inverse(x, mod())); }
    
    Modular& operator+=(const Modular& rhs) {
        x += rhs.x;
        if (x >= mod()) x -= mod();
        return *this;
    }
    Modular& operator-=(const Modular& rhs) {
        x -= rhs.x;
        if (x < 0) x += mod();
        return *this;
    }
    Modular& operator*=(const Modular& rhs) {
        x = normalize(1LL * x * rhs.x);
        return *this;
    }
    Modular& operator/=(const Modular& rhs) {
        return *this *= rhs.inv();
    }
    Modular operator-() const { return Modular(x == 0 ? 0 : mod() - x); }
    
    friend Modular operator+(Modular lhs, const Modular& rhs) { return lhs += rhs; }
    friend Modular operator-(Modular lhs, const Modular& rhs) { return lhs -= rhs; }
    friend Modular operator*(Modular lhs, const Modular& rhs) { return lhs *= rhs; }
    friend Modular operator/(Modular lhs, const Modular& rhs) { return lhs /= rhs; }

    friend bool operator==(const Modular& lhs, const Modular& rhs) { return lhs.x == rhs.x; }
    friend bool operator!=(const Modular& lhs, const Modular& rhs) { return lhs.x != rhs.x; }
    // ↓ Not a true numeric cmp, cause val(pre-mod) is unknown
    friend bool operator<(const Modular& lhs, const Modular& rhs) { return lhs.x < rhs.x; }
    
    friend std::ostream& operator<<(std::ostream& os, const Modular& num) {
        return os << num.x;
    }
    friend std::istream& operator>>(std::istream& is, Modular& num) {
        typename std::common_type<Type, i64>::type v;
        is >> v;
        num = Modular(v);
        return is;
    }
    
private:
    Type x;
};

// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& mod = VarMod::value;
// using Z = Modular<VarMod>;

constexpr int mod = 998244353;
// decltype(mod) 是 mod 的类型，比方说 const int&。
// decay<decltype(mod)>::type 会把 const 和 & 去掉，变成 int 类型。
// std::integral_constant<int> 会创建一个 int 类型的常量。
using Z = Modular<std::integral_constant<std::decay<decltype(mod)>::type, mod>>;
