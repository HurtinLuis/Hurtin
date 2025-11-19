struct DSU {
    std::vector<int> f, siz;

    DSU(int n = 0) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int root(int u) {
        if (u == f[u]) {
            return u;
        }
        return f[u] = root(f[u]);
    }

    bool merge(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) {
            return false;
        }
        f[v] = u;
        siz[u] += siz[v];
        return true;
    }

    bool same(int u, int v) { return root(u) == root(v); }
    int size(int u) { return siz[root(u)]; }
};

