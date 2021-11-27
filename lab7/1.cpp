#include <algorithm>
#include <iostream>
#include <set>

int main() {
    int k;
    std::cin >> k;
    std::vector<long long> a(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());


    std::set<std::vector<long long>> s;
    long long n;
    std::cin >> n;
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            for (int p = j + 1; p < k; ++p) {
                for (int l = p + 1; l < k; ++l) {
                    if (a[i] + a[j] + a[p] + a[l] == n) {
                        s.insert({a[i], a[j], a[p], a[l]});
                    }
                }
            }
        }
    }
    for (auto v : s) {
        for (int i = 0; i < 4; ++i) {
            std::cout << v[i] << ' ';
        }
        std::cout << '\n';
    }
}
