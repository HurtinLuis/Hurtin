// ------------------------- Hash -------------------------
#include <ext/pb_ds/assoc_container.hpp>

struct Hash {
    static u64 splitmix64(u64 x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(u64 x) const {
        static const u64 seed = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + seed);
    }
};

template <typename K, typename V, typename H = Hash>
using HashMap = __gnu_pbds::gp_hash_table<K, V, H>;

template <typename K, typename H = Hash>
using HashSet = HashMap<K, __gnu_pbds::null_type, H>;
