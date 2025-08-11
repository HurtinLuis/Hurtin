std::ostream &operator<<(std::ostream &os, u128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

u128 gcd(u128 a, u128 b) {
    return b == 0 ? a : gcd(b, a % b);
}
