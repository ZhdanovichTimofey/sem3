#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include <sstream>

class inputString{
	private:
		std::string reg, contract;
		int charge;
	public:
		friend std::fstream& operator>>(std::fstream &file, inputString &input){
			std::string line;
			getline(file, line);
			char place;
			char delimiter = ',';
			std::string reg, contract;
			std::stringstream stream(line); 
			getline(stream, reg, delimiter);
			getline(stream, contract, delimiter);
			input.reg = reg;
			input.contract = contract;
			return file;
		}
		
		std::string getreg(){
			return this->reg;
		}
		
		std::string getcontract(){
			return this->contract;
		}
};

class sub{
	public:
		std::string reg, contract;
		sub(std::string reg, std::string contract){
			this->reg = reg;
			this->contract = contract;
		}
};

bool operator<(sub const a, sub const b){
			if (a.reg < b.reg){
				return a.reg < b.reg;
			} else if (a.reg == b.reg){
				return a.contract < b.contract;
			} else {
				return a.reg < b.reg; 
			}
		}

int main(){
	std::fstream file, outputfile;
	inputString str;
	file.open("task2_input_0.txt");
	std::set<sub> subs;
	while (file >> str){
		subs.emplace(str.getreg(), str.getcontract());
	}
	std::cout << subs.size();
}
