#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<set>

class inputStringCalls{
	private:
		std::string in, sub;
		int time = 0;
	public:
		friend std::fstream& operator>>(std::fstream &file, inputStringCalls &input){
			std::string line;
			getline(file, line);
			char delimiter = ',';
			std::string in, sub;
			int time;
			std::stringstream stream(line); 
			getline(stream, in, delimiter);
			getline(stream, sub, delimiter);
			stream >> time;
			input.in = in;
			input.sub = sub;
			input.time = time;
			return file;
		}
		
		std::string getin(){
			return this->in;
		}
		
		std::string getsub(){
			return this->sub;
		}
		
		int gettime(){
			return this->time;
		}
};

class inputStringSpam{
	private:
		std::string number;
	public:
		friend std::fstream& operator>>(std::fstream &file, inputStringSpam &input){
			std::string number;
			getline(file, number);
			input.number = number;
			return file;
		}
		
		std::string getnumber(){
			return this->number;
		}
};



int main(){
	std::fstream filespam, filecalls;
	inputStringSpam str1;
	inputStringCalls str2;
	
	filespam.open("task2_inputspam.txt");
	std::set<std::string> spam;
	while (filespam >> str1){
		spam.insert(str1.getnumber());
	}
	
	filecalls.open("task2_inputcalls.txt");
	std::map<std::string, int> subs;
	while (filecalls >> str2){
		if (spam.find(str2.getin()) != spam.end()){
			if (subs.find(str2.getsub()) != subs.end()){
				subs.find(str2.getsub())->second += str2.gettime();
			} else {
				subs.insert({str2.getsub(), str2.gettime()});
			}
		}
	}
	int max = 0;
	std::string smax;
	for (auto &s: subs){
		if (s.second > max){
			smax = s.first;
			max = s.second;
		}
	}
	std::cout << smax << " " << max << '\n';
}
