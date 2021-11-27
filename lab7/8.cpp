#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<long long> stack;
    std::string tmp;
    std::cin >> tmp;
    while (tmp != "=") {
        if (tmp == "+") {
            long long second = stack.back();
            stack.pop_back();
            long long first = stack.back();
            stack.pop_back();
            stack.push_back(first + second);
        } else if (tmp == "-") {
            long long second = stack.back();
            stack.pop_back();
            long long first = stack.back();
            stack.pop_back();
            stack.push_back(first - second);
        } else if (tmp == "*") {
            long long second = stack.back();
            stack.pop_back();
            long long first = stack.back();
            stack.pop_back();
            stack.push_back(first * second);
        } else {
            stack.push_back(std::stoll(tmp));
        }
        std::cin >> tmp;
    }
    std::cout << stack.back() << '\n';
}
