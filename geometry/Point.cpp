// ----------------------------- Point -----------------------------
template <typename T>
struct Point {
    T x;
    T y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    template<class U> operator Point<U>() { return Point<U> (U(x), U(y)); }

    Point &operator+=(const Point &p) & {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) & {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(const T &v) & {
        x *= v;
        y *= v;
        return *this;
    }
    Point &operator/=(const T &v) & {
        x /= v;
        y /= v;
        return *this;
    }
    Point operator-() const {
        return Point(-x, -y);
    }
    friend Point operator+(Point a, const Point &b) {
        return a += b;
    }
    friend Point operator-(Point a, const Point &b) {
        return a -= b;
    }
    friend Point operator*(Point a, const T &b) {
        return a *= b;
    }
    friend Point operator/(Point a, const T &b) {
        return a /= b;
    }
    friend Point operator*(const T &a, Point b) {
        return b *= a;
    }
    friend bool operator==(const Point &a, const Point &b) {
        return a.x == b.x && a.y == b.y;
    }
    friend std::istream &operator>>(std::istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

template<class T> T dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y * b.y; }

template<class T> T cross(const Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }

template<class T> T square(const Point<T> &p) { return dot(p, p); }

template<class T> double length(const Point<T> &p) { return std::sqrt(square(p)); }

template<class T> Point<T> normalize(const Point<T> &p) { return p / length(p); }

template<class T> double distance(const Point<T> &a, const Point<T> &b) { return length(a - b); }

template<class T> Point<T> rotate(const Point<T> &a) { return Point(-a.y, a.x); }

template<class T> int sgn(const Point<T> &a) { return a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1; }

