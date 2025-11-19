<<<<<<< HEAD
// author: Hurtin
// last modified in: 2025/11/19
// #include <bits/stdc++.h>

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &a) {
    return os << "(" << a.first << ", " << a.second << ")";
};

template<class T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &a) {
    os << "(";
    for (int i = 0; i < N; i++) {
        if (i >= 100) {
            os << ", ..."; break;
        } if (i > 0) {
            os << ", ";
        } os << a[i];
    }
    return os << ")";
}

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
    os << "{";
    for (int i = 0; i < int(a.size()); i++) {
        if (i >= 100) {
            os << ", ..."; break;
        } if (i > 0) {
            os << ", ";
        }
        os << a[i];
    }
    return os << "}";
}


// ["0", "31", "32", "33", "34"] -> [reset, red, green, yellow, blue]
#define color(s) ("\x1b[" s "m")

template<typename... T>
void debug_out(const std::string &s, T&&... args) {
    std::string n = s;
    size_t pos = 0;
    int unpack[] = {0, (
        [&](){
            size_t comma = n.find(',', pos);
            std::string p = (comma == std::string::npos ? n.substr(pos) : n.substr(pos, comma - pos));
            std::cerr << color("33") << p << ": " << color("32") << forward<T>(args);
            pos = (comma == std::string::npos ? comma : comma + 1);
        }(), 0)...};
    (void)unpack;
    std::cerr << color("0") << std::endl;
}

#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
=======
// author: Hurtin
// last modified in: 2025:08:26
#include <bits/stdc++.h>

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &a) {
    return os << "(" << a.first << ", " << a.second << ")";
};

template<class T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &a) {
    os << "(";
    for (int i = 0; i < N; i++) {
        if (i >= 100) {
            os << ", ..."; break;
        } if (i > 0) {
            os << ", ";
        } os << a[i];
    }
    return os << ")";
}

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
    os << "{";
    for (int i = 0; i < int(a.size()); i++) {
        if (i >= 100) {
            os << ", ..."; break;
        } if (i > 0) {
            os << ", ";
        }
        os << a[i];
    }
    return os << "}";
}


// ["0", "31", "32", "33", "34"] -> [reset, red, green, yellow, blue]
#define color(s) ("\x1b[" s "m")

template<typename... T>
void debug_out(const std::string &s, T&&... args) {
    std::string n = s;
    size_t pos = 0;
    int unpack[] = {0, (
        [&](){
            size_t comma = n.find(',', pos);
            std::string p = (comma == std::string::npos ? n.substr(pos) : n.substr(pos, comma - pos));
            std::cerr << color("33") << p << ": " << color("32") << forward<T>(args);
            pos = (comma == std::string::npos ? comma : comma + 1);
        }(), 0)...};
    (void)unpack;
    std::cerr << color("0") << std::endl;
}

#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
>>>>>>> c576f1a39e510cfec4edb7fb908796568ade864f
