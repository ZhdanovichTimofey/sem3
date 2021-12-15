#include<cmath>
#include<thread>
#include<vector>
#include<utility>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<string>
#include<mutex>

class inputString{
	private:
		std::string word;
	public:
		inputString(){
		}
		friend std::ifstream& operator>>(std::ifstream &file, inputString &input){
			std::string word;
			getline(file, word);
			input.word = word;
			return file;
		}
		
		std::string getword(){
			return this->word;
		}
};

void counter(std::string name_of_file, std::map<std::string, int>* res){
	inputString str;
	std::map<std::string, int> words;
	std::ifstream file(name_of_file);
	std::mutex mutex;
	while (file >> str){
		words.emplace(str.getword(), 0);
		words.at(str.getword()) += 1;
	}
	mutex.lock();
	for (auto it = words.begin(); it != words.end(); ++it) {
    	res->emplace(it->first, 0);
    	res->at(it->first) += it->second;
	}
	mutex.unlock();
}

int main(){
	//std::thread th1, th2, th3, th4;
	std::map<std::string, int> res;
	std::thread th1(counter, "task2_input_0.txt", &res);
	std::thread th2(counter, "task2_input_1.txt", &res);
	std::thread th3(counter, "task2_input_2.txt", &res);
	std::thread th4(counter, "task2_input_3.txt", &res);
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	std::string wordmax;
	int nmax = 0;
	for (auto it =res.begin(); it != res.end(); ++it) {
    	if (it->second > nmax){
    		wordmax = it->first;
    		nmax = it->second;
		}
	}
	std::cout << nmax << " " << wordmax << '\n';
}
