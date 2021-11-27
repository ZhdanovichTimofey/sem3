#include<iostream>
#include<fstream>
#include<unordered_set>
#include<string>

class inputString{
	private:
		std::string sub;
	public:
		friend std::fstream& operator>>(std::fstream &file, inputString &input){
			std::string line;
			getline(file, line);
			input.sub = line;
			return file;
		}
		
		std::string getsub(){
			return this->sub;
		}
};

int main(){
	std::fstream file, outputfile;
	inputString str;
	file.open("task1_input_0.txt");
	outputfile.open("output1.txt");
	std::unordered_set<std::string> numbers;
	while (file >> str){
		numbers.emplace(str.getsub());
	}
	int counter = 0;
	for(auto s: numbers){
		counter += 1;
	}
	std::cout << counter;
}
