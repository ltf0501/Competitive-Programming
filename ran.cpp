mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int>(0, 1)(rng);
