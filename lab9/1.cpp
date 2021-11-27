#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<string>
#include <sstream>

class inputString{
	private:
		std::string word;
		int charge;
	public:
		friend std::fstream& operator>>(std::fstream &file, inputString &input){
			std::string word;
			getline(file, word);
			input.word = word;
			return file;
		}
		
		std::string getword(){
			return this->word;
		}
};



int main(){
	std::map<std::string, int> map;
	std::fstream file, outputfile;
	inputString str;
	file.open("task1_input.txt");
	while (file >> str){
		if (map.find(str.getword()) != map.end()){
			map.find(str.getword())->second += 1;
		} else {
			map.insert({str.getword(), 1});
		}
	}
	int max = 0;
	std::string smax;
	for (auto &s: map){
		if (s.second > max){
			smax = s.first;
			max = s.second;
		}
	}
	std::cout << smax << " " << max << '\n';
}
