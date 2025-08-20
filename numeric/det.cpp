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

        Z inv = a[i][i].inv();
        for (int j = i + 1; j < n; j++) {
            Z v = a[j][i] * inv;
            for (int k = i; k < n; k++) {
                a[j][k] -= a[i][k] * v;
            }
        }
        ans *= a[i][i];
    }
    return ans;
}
