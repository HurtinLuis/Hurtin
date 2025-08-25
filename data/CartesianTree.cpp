// ------------------------- Cartesian Tree -------------------------
template <typename T, bool IS_MIN>
struct CartesianTree {
    int n;
    std::vector<T> a;
    std::vector<std::pair<int, int>> range;
    std::vector<int> lch, rch, par;
    int root;

    CartesianTree(std::vector<T> &a_) : n((int) a_.size()), a(a_) {
        range.assign(n, {-1, -1});
        lch.assign(n, -1);
        rch.assign(n, -1);
        par.assign(n, -1);
        if (n == 1) {
            range[0] = {0, 1};
            root = 0;
            return;
        }

        auto is_sm = [&](int i, int j) -> bool {
            return IS_MIN ?
                (a[i] < a[j]) || (a[i] == a[j] && i < j) :
                (a[i] > a[j]) || (a[i] == a[j] && i < j);
        };

        std::vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && is_sm(i, stk.back())) {
                lch[i] = stk.back();
                stk.pop_back();
            }
            range[i].first = (stk.empty() ? 0 : stk.back() + 1);
            stk.push_back(i);
        }

        stk.clear();
        for (int i = n - 1; ~i; i--) {
            while (!stk.empty() && is_sm(i, stk.back())) {
                rch[i] = stk.back();
                stk.pop_back();
            }
            range[i].second = (stk.empty() ? n : stk.back());
            stk.push_back(i);
        }

        for (int i = 0; i < n; i++) if (lch[i] != -1) par[lch[i]] = i;
        for (int i = 0; i < n; i++) if (rch[i] != -1) par[rch[i]] = i;
        for (int i = 0; i < n; i++) if (par[i] == -1) root = i;
    }

    std::tuple<int, int, T> maxRectangle(int i) {
        auto [l, r] = range[i];
        return {l, r, a[i]};
    }

    T maxArea() {
        assert(IS_MIN);
        T res = 0;
        for (int i = 0; i < n; i++) {
            auto [l, r, h] = maxRectangle(i);
            res = std::max(res, (r - l) * h);
        }
        return res;
    }
};
