#include<iostream>
#include<string>



class weekday{
	int day1;
	int day2;
};

class human{
	public:
		human(std::string name = "aa"){
			this->born = 0;
			this->name = name;
			this->surname = "sss";
			this->ss = new int[1000];
		}
		
		~human(){
			delete[] ss;
		}
		int* ss;
		int born;
		std::string name;
		std::string surname;
		void operator+ (){
			std::cout << this->name << '\n';
		}
};

int main(){
	human liza, tim("tim");
	liza.name = "liza";
	liza + ;
	tim + ;
}
