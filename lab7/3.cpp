#include<iostream>
#include<array>
#include<string>
#include<algorithm>
#include<set>
#include<vector>

int main() {
	int n = 0, k = 0;
	std::cin >> n;
	std::set<int> s;
	for (int i = 0; i < n; ++i) {
		std::cin >> k;
		s.insert(k);
	}
	std::cout << s.size();
}
