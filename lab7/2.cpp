#include<iostream>
#include<array>
#include<string>
#include<algorithm>
#include<set>

struct {
        bool operator()(std::string a, std::string b) const { return a > b; }
    } compare;

int main(){
	std::array<std::string, 1000> input;
	int n = 0;
	char a = 'q';
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >>	input.at(i);
		for (int j = 0; j < input.at(i).size(); ++j) {
			if (input.at(i).at(j) <= 'Z') {
				input.at(i).at(j) += 'a' - 'A';
			}
		}
	}
	std::sort(input.begin(), input.begin() + n, compare);
	std::set<std::string> s;
	std::vector<std::string> output;
	for (int i = 0; i < n; ++i) {
		s.insert(input.at(i));
	}
	int i = 0;
	for (auto v: s) {
		output.push_back(v);
	}	
	for (int i = output.size() - 1; i >= 0; --i){
		std::cout << output.at(i) << ' ';
	}
}
