#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
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
			std::getline(file, line);
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
			if ((this->sub[0] != '7') || (this->sub.size() != 11)){
				throw 100 + 1;
			}
			for (int i = 1; i < 11; ++i){
				if ((this->sub[i] > '9') || (this->sub[i] < '0')){
					throw 100 + i;
				}		
			}
			return this->sub;
		}
		
		std::string getcaller(){
			if ((this->caller[0] != '7') || (this->caller.size() != 11)){
				throw 200 + 1;
			}
			for (int i = 0; i < 11; ++i){
				if ((this->caller[i]  > '9') || (this->caller[i] < '0')){
					throw 200 + i;
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
	std::ifstream file("task2_input.txt");
	std::ofstream outputfile("task2_output.txt");
	std::ofstream fileerrors("task2_errors.txt");
	std::unordered_set<std::string> unique;
	int k = 0;
	try{
		while (file >> str){
			std::string s1 = str.getsub();
			std::string s2 = str.getcaller();
			unique.insert(s1);
			unique.insert(s2);
			k++;		
		}	
	}
	catch(...) {
		fileerrors << str.getnumber() << '\n';
		outputfile << k << '\n';
		outputfile << unique.size() << '\n';
		file.close();
		outputfile.close();
		fileerrors.close();
	} 	
}
