#include <stack>
#include <iostream>
#include <string>

int main(){
	std::stack <int> stek;
	std::string s;
	int t = 0;
	while (std::cin >> s){
		if ((s == "*")){
			t = stek.top();
			stek.pop();
			stek.top() *= t;
		} else
		if ((s == "+")){
			t = stek.top();
			stek.pop();
			stek.top() += t;
		} else
		if ((s == "-")){
			t = stek.top();
			stek.pop();
			stek.top() -= t;
		} else
		if ((s == "/")){
			t = stek.top();
			stek.pop();
			stek.top() /= t;
		} else {
			t = std::stoi(s);
			stek.push(t);
		}
	}
	std::cout << stek.top();
}
