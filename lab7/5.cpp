#include <stack>
#include <iostream>

int main(){
	std::stack <int> stek;
	int in = 1;
	while (in != 0){
		std::cin >> in;
		if (in == 0){
			continue;
		}
		if (in > 0){
			stek.push(in); 
		} else
		if (!stek.empty()){
		if (in > -stek.top()){
			stek.top() += in;
		} else
			stek.pop();			
		}
	}
	int size = stek.size();
	int top = -1;
	if (!stek.empty())
		top = stek.top();
	std::cout << size << " " << top;  
}

