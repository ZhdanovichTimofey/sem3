#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<unordered_set>

class inputString{
	private:
		std::string sub;
		std::string caller;
	public:
		inputString(){
		}
		friend std::ifstream& operator>>(std::ifstream &file, inputString &input){
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
		
		std::string getsub(){
			return this->sub;
		}
		
		std::string getcaller(){
			return this->caller;
		}
		
		bool is_spam() const {
			if (this->caller.substr(4) == "7800"){
				return true;
			}
			return false;
		}
};

void iter(std::istream file, inputString str, std::unordered_set<std::string> unique) {
	std::cout << 1 << '\n';
		if (str.is_spam()){
			unique.insert(str.getsub());
		}
		if (file >> str){
			iter(file, str, &unique);
		}
}

int main(){
	inputString str;
	std::ifstream file("input.txt");
	std::ofstream outputfile("output.txt");
	std::unordered_set<std::string> unique;
	iter(&file >> str, &str, &unique);
	file.close();
	outputfile.close();	
}
