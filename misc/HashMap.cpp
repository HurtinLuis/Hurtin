std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct Hash {
    static u64 splitMix64(u64 x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(u64 x) const noexcept {
        return splitMix64(x + seed);
    }
private:
    u64 seed = rng();
};

