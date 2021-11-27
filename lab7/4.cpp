#include <algorithm>
#include <iostream>
#include <map>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::map<std::string, long long> s;
    for (int i = 0; i < n; ++i) {
        std::string tmp;
        std::cin >> tmp;
        for (int j = 0; j < tmp.size(); ++j) {
            if ('A' <= tmp[j] && tmp[j] <= 'Z') {
                tmp[j] = 'a' + (tmp[j] - 'A');
            }
        }
        ++s[tmp];
    }
    std::string ans = "";
    long long cnt = 0;
    for (auto& pair : s) {
        if (pair.second > cnt) {
            ans = pair.first;
            cnt = pair.second;
        }
    }
    if (cnt != 0) {
        std::cout << ans << ' ' << cnt << '\n';
    }
}
