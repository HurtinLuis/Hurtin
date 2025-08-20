// ------------------------- SegmentTree -------------------------
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<int> tag;
    
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v = Info()) {
        n = n_;
        init(std::vector(n, v));
    }
    
    template<class T>
    SegmentTree(std::vector<T> init_) {
        n = int(init_.size());
        init(init_);
    }
    
    template<class T>
    void init(std::vector<T> init_) {
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), 0);
        auto build = [&](auto &&self, int p, int l, int r) -> void {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m);
            self(self, 2 * p + 1, m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }
    
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    
    void apply(int p, int v) {
        tag[p] += v;
        info[p].max += v;
    }
    
    void push(int p) {
        if (tag[p] != 0) {
            apply(2 * p, tag[p]);
            apply(2 * p + 1, tag[p]);
            tag[p] = 0;
        }
    }
    
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            tag[p] = 0;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        push(p);
        int m = (l + r) / 2;
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }
    
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
    
    void rangeApply(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        push(p);
        int m = (l + r) / 2;
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    
    void rangeAdd(int l, int r, int v) {
        rangeApply(1, 0, n, l, r, v);
    }
};

constexpr int inf = 1E9;
struct Info {
    int max = -inf;
};

Info operator+(const Info &l, const Info &r) {
    return {
        std::max(l.max, r.max)
    };
}

