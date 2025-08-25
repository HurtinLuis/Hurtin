template <typename T, typename F>
class SparseTable {
public:
    int n;
    std::vector<std::vector<T>> st;
    F fun;

    SparseTable(const std::vector<T> &a, const F &f) : fun(f) {
        n = int(a.size());
        int h = std::__lg(n) + 1;
        st.assign(n, std::vector<T>(h));

        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < h; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                st[i][j] = fun(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n - 1);
        int k = std::__lg(r - l + 1);
        return fun(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

// Example:
// SparseTable st(a, [](int u, int v) { return std::max(u, v); });
