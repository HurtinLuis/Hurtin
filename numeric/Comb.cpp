// ------------------------- Comb -------------------------
std::vector<Z> F(1, 1);
std::vector<Z> iF(1, 1);

void init_fact(int m) {
    const int n = int(F.size()) - 1;
    if (m <= n) {
        return;
    }
    F.resize(m + 1);
    iF.resize(m + 1);

    for (int i = n + 1; i <= m; i++) {
        F[i] = F[i - 1] * i;
    }
    iF[m] = F[m].inv();
    for (int i = m; i > n; i--) {
        iF[i - 1] = iF[i] * i;
    }
}

Z fact(int m) {
    if (int(F.size()) < m) {
        init_fact(2 * m);
    }
    return F[m];
}

Z inv_fact(int m) {
    if (int(F.size()) < m) {
        init_fact(2 * m);
    }
    return iF[m];
}

Z C(int n, int m) {
    if (n < m || m < 0) {
        return 0;
    }
    return fact(n) * inv_fact(m) * inv_fact(n - m);
}
