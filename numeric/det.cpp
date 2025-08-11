Z det(std::vector<std::vector<Z>> a) {
    int n = int(a.size());
    Z ans = 1;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && a[j][i] == 0) {
            j++;
        }
        if (j == n) return 0;
        if (i != j) {
            std::swap(a[i], a[j]);
            ans *= -1;
        }
        ans *= a[i][i];
        auto v = Z(a[i][i]).inv();
        for (int j = i; j < n; j++) {
            a[i][j] *= v;
        }
        for (int j = i + 1; j < n; j++) {
            Z v = a[j][i];
            for (int k = i; k < n; k++) {
                a[j][k] -= a[i][k] * v;
            }
        }
    }
    return ans;
}
