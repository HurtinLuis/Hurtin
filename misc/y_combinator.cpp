template<class F>
class y_combinator {
public:
    template<class T>
    explicit y_combinator(T &&f) : fun(std::forward<T>(f)) {}

    template<class... Args>
    decltype(auto) operator()(Args &&...args) {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }

private:
    F fun;
};

template<class F>
decltype(auto) dfs(F &&f) {
    return y_combinator<std::decay_t<F>>(std::forward<F>(f));
}

