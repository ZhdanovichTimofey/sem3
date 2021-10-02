#include<string>
#include<iostream>

std::string name(int k){
			if (k == 1)
				return "monday";
			if (k == 2)
				return "tuesday";
			if (k == 3)
				return "wednesday";
			if (k == 4)
				return "thursday";
			if (k == 5)
				return "friday";
			if (k == 6)
				return "saturday";
			if (k == 7)
				return "sunday";
		}

class Weekday{
	private:
		std::string day;
	public:
		std::string show(){
			return day;
		}
		void put(std::string n){
			this->day = n;
		}
		int number(){
			if (this->day == "monday")
				return 1;
			if (this->day == "tuesday")
				return 2;
			if (this->day == "wednesday")
				return 3;
			if (this->day == "thursday")
				return 4;
			if (this->day == "friday")
				return 5;
			if (this->day == "saturday")
				return 6;
			if (this->day == "sunday")
				return 7;
		}
};

template <class T>
void tsort(T* start, int size){
	T current = start[0];
	int j = 0;
	for (int i = 1; i < size; ++i){
		current = start[i];
		j = i;
		while ((start[j - 1] > current) and (j > 0)){
			start[j] = start[j - 1];
			start[j - 1] = current;
			--j;
		}
	}
}

template <>
void tsort(Weekday* start, int size){
	int* a = new int[7];
	for (int i = 0; i < 7; ++i){
		a[i] = 0;
	}
	for (int i = 0; i < size; ++i){
		a[start[i].number() - 1] += 1;
	}
	int k = 0;
	for (int i = 0; i < 7; ++i){
		for(int j = 0; j < a[i]; ++j){
			start[k].put(name(i+1));
			k++;
		}
	}
}

int main(){
	
	int a1[3] = {1, 2, 3}; 
	
	int* a = new int[3];
	
	double* b = new double[3];
	std::string* c = new std::string[3];
	Weekday* d = new Weekday[3];
	d[0].put("tuesday");
	d[1].put("tuesday");
	d[2].put("monday");
	for (int i = 0; i < 3; ++i){
		a[i] = 4 - i;
		b[i] = 3.145 - i;
		c[i] = "wre"; 
	}
	tsort<int>(a, 3);
	tsort<double>(b, 3);
	tsort<std::string>(c, 3);
	tsort<Weekday>(d, 3);
	for (int i = 0; i < 3; ++i){
		std::cout << d[i].show() << '\n';
	} 
}
