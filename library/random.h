#include <random>
#include <chrono>

struct RandomGenerator {
    std::mt19937_64 rng;

    RandomGenerator() {
        rng.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    }

    template<class T>
    T randInt(T l, T r) {
        std::uniform_int_distribution<T> distribution(l, r);
        return distribution(rng);
    }

    template<class T>
    T randFloat(T l, T r) {
        std::uniform_real_distribution<T> distribution(l, r);
        return distribution(rng);
    }
};