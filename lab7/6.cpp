#include <deque>
#include <stack>
#include <iostream>
#include <string>

int main(){
	std::deque <std::string> q;
	std::string s;
	int n=0;
	std::cin >> n;
	for (int i = 0; i < n; ++i){
		std::cin >> s;
		if ((s == "*")){
			std::cin >> s;
			q.insert(q.begin() + q.size()/2 + q.size() % 2, s);
		} else
		if ((s == "+")){
			std::cin >> s;
			q.push_back(s);
		} else
		if ((s == "-")){
			std::cout << q.front() << "\n";
			q.pop_front();
		}
	}
}
