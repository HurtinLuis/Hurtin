std::vector<Z> F(1, 1);
std::vector<Z> iF(1, 1);

Z factorial(int n) {
    while ((int) F.size() < n + 1) {
        F.push_back(F.back() * (int) F.size());
        iF.push_back(1 / F.back());
    }
    return F[n];
}

Z C(int n, int m) {
    if (n < m || m < 0) {
        return 0;
    }
    return factorial(n) * iF[m] * iF[n - m];
}