#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<optional>
#include<unordered_set>

class inputString{
	private:
		std::string sub;
		std::string caller;
		int number = 0;
	public:
		inputString(){
		}
		friend std::ifstream& operator>>(std::ifstream &file, inputString &input){
			input.number += 1;
			std::string line;
			getline(file, line);
			char place;
			char delimiter = ',';
			std::string sub, caller;
			std::stringstream stream(line); 
			getline(stream, caller, delimiter);
			getline(stream, sub, delimiter);
			input.sub = sub;
			input.caller = caller;
			return file;
		}
		
		std::optional<std::string> getsub(){
			if ((this->sub[0] != '7') || (this->sub.size() != 11)){
				return {};
			}
			for (int i = 0; i < 11; ++i){
				if ((this->sub[i] > '9') || (this->sub[i] < '0')){
					return {};
				}		
			}
			return this->sub;
		}
		
		std::optional<std::string> getcaller(){
			if ((this->caller[0] != '7') || (this->caller.size() != 11)){
				return {};
			}
			for (int i = 0; i < 11; ++i){
				if ((this->caller[i]  > '9') || (this->caller[i] < '0')){
					return {};
				}		
			}
			return this->caller;
		}
		
		int getnumber(){
			return this->number;
		}
};

int main(){
	inputString str;
	std::ifstream file("task1_input.txt");
	std::ofstream outputfile("task1_output.txt");
	std::ofstream fileerrors("task1_errors.txt");
	std::unordered_set<std::optional<std::string>> unique;
	while (file >> str){
		if ((!str.getcaller().has_value()) || (!str.getsub().has_value())){
			fileerrors << str.getnumber() << '\n';
		} else {
			unique.insert(str.getsub());
			unique.insert(str.getcaller());
		}
	}
	outputfile << unique.size() << '\n';
	file.close();
	outputfile.close();
	fileerrors.close();	
}
