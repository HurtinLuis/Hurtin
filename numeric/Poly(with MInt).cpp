// ------------------------- Poly -------------------------
#define siz(p) int(p.size())

template<int P>
constexpr MInt<P> primitiveRoot() {
    MInt<P> i = 2;
    int k = __builtin_ctz(P - 1);
    while (true) {
        if (power(i, (P - 1) / 2) != 1) {
            break;
        }
        i += 1;
    }
    return power(i, (P - 1) >> k);
}

template<int P>
constexpr MInt<P> pRoot = primitiveRoot<P>();

template<>
constexpr MInt<998244353> pRoot<998244353> {31};

template<>
constexpr MInt<1000000007> pRoot<1000000007> {5};

std::vector<int> rev;
std::vector<Z> roots{0, 1};

// make it understandable one day...
void dft(std::vector<Z> &a) {
    int n = siz(a);
    if (siz(rev) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    for (int i = 0; i < n; i++) {
        if (rev[i] < i) {
            std::swap(a[i], a[rev[i]]);
        }
    }

    if (siz(roots) < n) {
        int k = __builtin_ctz(siz(roots));
        roots.resize(n);
        while ((1 << k) < n) {
            auto e = power(pRoot<P>, 1 << (__builtin_ctz(P - 1) - k - 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                Z u = a[i + j];
                Z v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}

// void dft(std::vector<Z> &a) {
//     int n = siz(a);
//     if (n == 1) {
//         return;
//     }

//     std::vector<Z> even(n / 2), odd(n / 2);
//     for (int i = 0; i < n / 2; i++) {
//         even[i] = a[i * 2];
//         odd[i] = a[i * 2 + 1];
//     }
//     dft(even);
//     dft(odd);

//     Z root = power(pRoot<P>, (P - 1) / n);
//     Z w = 1;
//     for (int i = 0; i < n / 2; i++) {
//         Z u = even[i];
//         Z v = odd[i] * w;
//         a[i] = u + v;
//         a[i + n / 2] = u - v;
//         w *= root;
//     }
// }

void idft(std::vector<Z> &a) {
    int n = siz(a);
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    Z inv = Z(1 - P) / n;
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}

struct Poly : public std::vector<Z> {
    Poly() : std::vector<Z>() {}
    explicit Poly(int n) : std::vector<Z>(n) {}

    explicit Poly(const std::vector<Z> &a) : std::vector<Z>(a) {}
    Poly(const std::initializer_list<Z> &a) : std::vector<Z>(a) {}

    template<class InputIt, class = std::_RequireInputIter<InputIt>>
    explicit Poly(InputIt first, InputIt last) : std::vector<Z>(first, last) {}

    Poly shift(int k) const {
        if (k >= 0) {
            auto b = *this;
            b.insert(b.begin(), k, 0);
            return b;
        } else if ((int) this->size() <= -k) {
            return Poly();
        } else {
            return Poly(this->begin() + (-k), this->end());
        }
    }

    Poly trunc(int k) const {
        Poly f = *this;
        f.resize(k);
        return f;
    }

    friend Poly operator+(const Poly &a, const Poly &b) {
        Poly res(std::max(siz(a), siz(b)));
        for (int i = 0; i < siz(a); i++) {
            res[i] += a[i];
        }
        for (int i = 0; i < siz(b); i++) {
            res[i] += b[i];
        }
        return res;
    }

    friend Poly operator-(const Poly &a, const Poly &b) {
        Poly res(std::max(siz(a), siz(b)));
        for (int i = 0; i < siz(a); i++) {
            res[i] += a[i];
        }
        for (int i = 0; i < siz(b); i++) {
            res[i] -= b[i];
        }
        return res;
    }
    friend Poly operator-(const Poly &a) {
        std::vector<Z> res(siz(a));
        for (int i = 0; i < siz(res); i++) {
            res[i] = -a[i];
        }
        return Poly(res);
    }

    friend Poly operator*(Poly a, Poly b) {
        if (a.empty() || b.empty()) {
           return Poly();
        }
        int n = 1, m = a.size() + b.size() - 1;
        while (n < m) {
            n *= 2;
        }
        a.resize(n);
        b.resize(n);

        dft(a);
        dft(b);
        for (int i = 0; i < n; i++) {
            a[i] *= b[i];
        }
        idft(a);
        a.resize(m);
        return a;
    }
    friend Poly operator*(Z a, Poly b) {
        for (int i = 0; i < siz(b); i++) {
            b[i] *= a;
        }
        return b;
    }
    friend Poly operator*(Poly a, Z b) {
        for (int i = 0; i < siz(a); i++) {
            a[i] *= b;
        }
        return a;
    }

    Poly &operator+=(const Poly &b) {
        return *this = *this + b;
    }
    Poly &operator-=(const Poly &b) {
        return *this = *this - b;
    }
    Poly &operator*=(Poly b) {
        return *this = *this * b;
    }
    Poly &operator*=(Z b) {
        return *this = *this * b;
    }

    Poly deriv() const {
        if (this->empty()) {
            return Poly();
        }
        int n = this->size();
        Poly res(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            res[i] = (i + 1) * (*this)[i + 1];
        }
        return res;
    }

    Poly integr() const {
        int n = this->size();
        Poly res(n + 1);
        for (int i = 0; i < n; ++i) {
            res[i + 1] = (*this)[i] / (i + 1);
        }
        return res;
    }
};

#undef siz
