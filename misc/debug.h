// author: tourist
// modified by: Hurtin (2025/11/20)

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <tuple>
#include <utility>

namespace std {

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string) s); }

string to_string(char s) { return string(1, s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < int(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += char('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    auto [a, b, c] = p;
    return "(" + to_string(a) + ", " + to_string(b) + ", " + to_string(b) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    auto [a, b, c, d] = p;
    return "(" + to_string(a) + ", " + to_string(b) + ", " + to_string(b) + ", " + to_string(d) + ")";
}

} // namesapce std


// ["0", "31", "32", "33", "34", "35"] -> [reset, red, green, yellow, blue, purple]
#define color(s) ("\x1b[" s "m")

template<typename... T>
void debug_out(const std::string &s, T&&... args) {
    using namespace std;
    string n = s;
    size_t pos = 0;
    int unpack[] = {0, (
        [&]() {
            size_t comma = n.find(',', pos);
            string p = (comma == string::npos ? n.substr(pos) : n.substr(pos, comma - pos));
            cerr << color("32") << p << color("0") << ": " << to_string(forward<T>(args)) << " ";
            pos = (comma == string::npos ? comma : comma + 1);
        }(), 0)...};
    (void)unpack;
    cerr << color("0") << endl;
}

#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)

// void debug_out() { std::cerr << std::endl; }

// template <typename Head, typename... Tail>
// void debug_out(Head H, Tail... T) {
//     std::cerr << " " << std::to_string(H);
//     debug_out(T...);
// }

// #define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]"; debug_out(__VA_ARGS__);
