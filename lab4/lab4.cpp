#include<fstream>
#include<iostream>
#include<string>
#include <sstream>

class inputString{
	private:
		std::string sub;
		std::string caller;
		int charge;
	public:
		inputString(){
			this->charge = 0;
		}
		friend std::fstream& operator>>(std::fstream &file, inputString &input){
			std::string line;
			getline(file, line);
			char place;
			char delimiter = ',';
			std::string charcharge, sub, caller;
			std::stringstream stream(line); 
			getline(stream, sub, delimiter);
			getline(stream, caller, delimiter);
			getline(stream, charcharge, delimiter);
			if (charcharge != "")
				input.charge = std::stoi(charcharge);
			input.sub = sub;
			input.caller = caller;
			return file;
		}
		
		std::string getsub(){
			return this->sub;
		}
		
		int getcharge(){
			return this->charge;
		}
};

class subscriber{
	private:
		std::string number;
		int bill;
	public:
		subscriber(){
			this->bill = 0;
		}
		
		std::string getname(){
			return this->number;
		}
		
		int getbill(){
			return this->bill;
		}
		
		bool check(std::string num){
			if (num != this->number)
				return 0;
			return 1;
		}
		
		void add(int inc){
			this->bill += inc;	
		}
		
		void put(std::string num, int inc){
			this->bill = inc;
			this->number = num;
		}
};

subscriber* extend(subscriber* subs, int n){
	subscriber* newsubs = new subscriber[2 * n];
	for (int i = 0; i < n; ++i){
		newsubs[i] = subs[i];
	}
	delete[] subs;
	return newsubs;
}

int main(){
	std::fstream file, outputfile;
	inputString str;
	file.open("input_file.txt");
	outputfile.open("output.txt");
	int n = 1000;
	subscriber* subs = new subscriber[n];
	int k = 0;
	while (file >> str){
		if (k = n){
			subs = extend(subs, n);
			n *= 2;
		}
		int i = 0;
		while ( (i < k) and (!subs[i].check(str.getsub())))
			i++;
		if (i < k){
			subs[i].add(str.getcharge());
		} else {
			subs[i].put(str.getsub(), str.getcharge());
		}
		++k;		
	}
	int max = 0;
	for (int i = 0; i < k; ++i){
		if (subs[i].getbill() > subs[max].getbill()){
			max = i;
		}
	}
	outputfile << subs[max].getname() << " " << subs[max].getbill() << '\n';
	file.close();
	outputfile.close();	
}
